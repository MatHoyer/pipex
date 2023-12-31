/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:56:54 by mhoyer            #+#    #+#             */
/*   Updated: 2023/07/03 08:33:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_first(t_pipex *pip, int i)
{
	int	file;

	if (pipe(pip->fd_pipe[i]) == -1)
		free_all(pip, "Error : Bad alloc");
	pip->pid[i] = fork();
	if (pip->pid[i] == -1)
	{
		close(pip->fd_pipe[i][0]);
		close(pip->fd_pipe[i][1]);
		free_all(pip, "Error : Bad alloc");
	}
	if (pip->pid[i] == 0)
	{
		if (access(pip->infile, F_OK | R_OK) == -1)
		{
			close(pip->fd_pipe[i][0]);
			close(pip->fd_pipe[i][1]);
			free_all(pip, "Error : No infile");
		}
		file = open(pip->infile, O_RDONLY);
		first(pip, pip->fd_pipe[i], file);
		close(file);
	}
	close(pip->fd_pipe[i][1]);
}

void	do_one_more(t_pipex *pip, int i)
{
	if (pipe(pip->fd_pipe[i]) == -1)
		free_all(pip, "Error : Bad alloc");
	pip->pid[i] = fork();
	if (pip->pid[i] == -1)
	{
		close(pip->fd_pipe[i][0]);
		close(pip->fd_pipe[i][1]);
		free_all(pip, "Error : Bad alloc");
	}
	if (pip->pid[i] == 0)
		one_more(pip, pip->fd_pipe[i - 1], pip->fd_pipe[i]);
	close(pip->fd_pipe[i - 1][0]);
	close(pip->fd_pipe[i][1]);
}
