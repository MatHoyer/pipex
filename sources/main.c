/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:18:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 11:18:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_pipex *pip)
{
	int	i;

	i = 0;
	while (i < pip->nb_cmd)
	{
		wait(pip->pid);
		i++;
	}
}

void	creat_tab(t_pipex *pip)
{
	int	i;

	i = -1;
	pip->pid = malloc(sizeof(pid_t) * pip->nb_cmd);
	if (!pip->pid)
		free_all(pip, "Error : Bad alloc");
	pip->fd_pipe = malloc(sizeof(int *) * pip->nb_cmd - 1);
	if (!pip->fd_pipe)
		free_all(pip, "Error : Bad alloc");
	while (++i < pip->nb_cmd - 1)
	{
		pip->fd_pipe[i] = malloc(sizeof(int) * 2);
		if (!pip->fd_pipe[i])
			free_all(pip, "Error : Bad alloc");
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex_mem;
	int		i;

	if (ac < 5)
		exit(msg_error("Error : ./pipex needs at least 5 arguments"));
	pipex_mem.cmd = NULL;
	pipex_mem.infile = av[1];
	pipex_mem.outfile = av[ac - 1];
	pipex_mem.nb_cmd = ac - 3;
	pipex_mem.all_path = get_path(env);
	i = -1;
	while (++i < pipex_mem.nb_cmd)
		ft_lstadd_back(&pipex_mem.cmd, ft_lstnew(av[i + 2], i));
	creat_tab(&pipex_mem);
	pipex(&pipex_mem);
	free_all(&pipex_mem, "");
	return (0);
}
