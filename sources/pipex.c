/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:27:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 08:38:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_cmp(t_pipex *pip)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(pip->cmd->split[0]);
	j = 0;
	while (pip->cmd->split[0][i] != '/')
		i--;
	tmp = malloc(ft_strlen(pip->cmd->split[0]) - i);
	i++;
	while (pip->cmd->split[0][i])
	{
		tmp[j] = pip->cmd->split[0][i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(pip->cmd->split[0]);
	pip->cmd->split[0] = tmp;
}

char	*get_cmd(t_pipex *pip)
{
	char	*a_return;
	int		i;

	i = -1;
	if (pip->cmd->split[0][0] == '/')
	{
		if (access(pip->cmd->split[0], F_OK | X_OK) == -1)
			free_all(pip, "Error : Cmd not found");
		a_return = ft_strdup(pip->cmd->split[0]);
		dup_cmp(pip);
		return (a_return);
	}
	while (pip->all_path && pip->all_path[++i])
	{
		a_return = ft_strjoin(pip->all_path[i], pip->cmd->split[0]);
		if (access(a_return, F_OK | X_OK) != -1)
			return (a_return);
		free(a_return);
	}
	return (NULL);
}

void	first(t_pipex *pip, int fd_pipe[2], int infile)
{
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	dup2(infile, 0);
	close(infile);
	pip->cmd->split = ft_split(pip->cmd->content, ' ');
	pip->cmd->path = get_cmd(pip);
	if (pip->cmd->path == NULL)
	{
		free_mat(pip->cmd->split);
		free(pip->cmd->path);
		free_all(pip, "Error : Cmd not found");
	}
	execve(pip->cmd->path, pip->cmd->split, NULL);
}

void	last(t_pipex *pip, int fd_pipe[2], int outfile)
{
	dup2(fd_pipe[0], 0);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	dup2(outfile, 1);
	close(outfile);
	pip->cmd->split = ft_split(pip->cmd->content, ' ');
	pip->cmd->path = get_cmd(pip);
	if (pip->cmd->path == NULL)
	{
		free_mat(pip->cmd->split);
		free(pip->cmd->path);
		free_all(pip, "Error : Cmd not found");
	}
	execve(pip->cmd->path, pip->cmd->split, NULL);
}

void	pipex(t_pipex *pip)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_file[2];
	int		fd_pipe[2];

	pip->first_cmd = pip->cmd;
	pipe(fd_pipe);
	fd_file[0] = open(pip->infile, O_RDONLY);
	fd_file[1] = open(pip->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	pid1 = fork();
	if (pid1 == 0)
		first(pip, fd_pipe, fd_file[0]);
	pip->cmd = pip->cmd->next;
	pid2 = fork();
	if (pid2 == 0)
		last(pip, fd_pipe, fd_file[1]);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	wait_all(pip);
	close(fd_file[0]);
	close(fd_file[1]);
}
