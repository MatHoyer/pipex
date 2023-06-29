/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:59:10 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:44:15 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	free_all(t_pipex *pip, char *msg)
{
	t_list	*n;
	//int		i;

	if (pip->all_path)
		free_mat(pip->all_path);
	while (pip->first_cmd)
	{
		n = pip->first_cmd->next;
		free(pip->first_cmd);
		pip->first_cmd = n;
	}
	// if (pip->pid)
	// 	free(pip->pid);
	// i = -1;
	// while (pip->fd_pipe[++i])
	// {
	// 	free(pip->fd_pipe[i]);
	// }
	// free(pip->fd_pipe);
	if (msg[0])
		exit(msg_error(msg));
}
