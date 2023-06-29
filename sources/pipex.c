/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:27:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:19:50 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first(t_pipex *pip, int fd_pipe[2])
{
	int	infile;

	if (access(pip->infile, F_OK | R_OK) == -1)
		free_all(pip, "Error : No infile");
	infile = open(pip->infile, O_RDONLY);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	dup2(infile, 0);
	close(infile);
	if (!pip->cmd->content || pip->cmd->content[0] == '\0')
		free_all(pip, "Error : Cmd not found");
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

void	last(t_pipex *pip, int fd_pipe[2])
{
	int	outfile;

	outfile = open(pip->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		free_all(pip, "Error : No outfile");
	dup2(fd_pipe[0], 0);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	dup2(outfile, 1);
	close(outfile);
	if (!pip->cmd->content || pip->cmd->content[0] == '\0')
		free_all(pip, "Error : Cmd not found");
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
	int		fd_pipe[2];

	pip->first_cmd = pip->cmd;
	pipe(fd_pipe);
	pid1 = fork();
	if (pid1 == 0)
		first(pip, fd_pipe);
	pip->cmd = pip->cmd->next;
	pid2 = fork();
	if (pid2 == 0)
		last(pip, fd_pipe);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	wait_all(pip);
}
