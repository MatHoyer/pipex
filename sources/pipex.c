/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:27:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/28 15:24:21 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_pipex *pip, int fd_pipe[2], int state)
{
	int	fd;
	
	if (state == 0)
	{
		fd = open(pip->infile, O_RDONLY);
		dup2(fd, 0);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
	}
	else
	{
		fd = open(pip->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(fd, 1);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
	}
	execve(pip->cmd->path, pip->cmd->split, NULL);
}

void	pipex(t_pipex *pip, char **env)
{
	pid_t	pid;
	int		i;
	int		fd_pipe[2];
	char	**commande;

	i = 0;
	while (pip->cmd)
	{
		pipe(fd_pipe);
		pid = fork();
		if (pid == -1)
			free_all(pip, "Error : Bad fork");
		if (pid == 0)
		{
			commande = get_path(env);
			if (commande == NULL || get_cmd(pip->cmd, commande))
			{
				free_mat(commande);
				free_all(pip, "Error : Cmd not found");
			}
			free_mat(commande);
			exec(pip, fd_pipe, i);
		}
		i = 1;
		pip->cmd = pip->cmd->next;
	}
}
