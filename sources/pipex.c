/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:27:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 11:12:33 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first(t_pipex *pip, int fd_pipe[2])
{
	int	infile;

	if (access(pip->infile, F_OK | R_OK) == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		free_all(pip, "Error : No infile");
	}
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
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		free_all(pip, "Error : No outfile");
	}
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

void	one_more(t_pipex *pip, int fd_prec[2], int fd_pipe[2])
{
	dup2(fd_prec[0], 0);
	close(fd_prec[1]);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
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
	int	i;
	int	j;

	i = -1;
	pip->first_cmd = pip->cmd;
	while (++i < pip->nb_cmd)
	{
		if (i == 0)
		{
			pipe(pip->fd_pipe[i]);
			pip->pid[i] = fork();
			if (pip->pid[i] == 0)
				first(pip, pip->fd_pipe[i]);
		}
		else if (i == pip->nb_cmd - 1)
		{
			pip->pid[i] = fork();
			if (pip->pid[i] == 0)
				last(pip, pip->fd_pipe[i - 1]);
		}
		else
		{
			pipe(pip->fd_pipe[i]);
			pip->pid[i] = fork();
			if (pip->pid[i] == 0)
				one_more(pip, pip->fd_pipe[i - 1], pip->fd_pipe[i]);
		}
		pip->cmd = pip->cmd->next;
	}
	j = -1;
	while (++j < pip->nb_cmd - 1)
	{
		close(pip->fd_pipe[j][0]);
		close(pip->fd_pipe[j][1]);
	}
	wait_all(pip);
}
