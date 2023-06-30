/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:27:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/30 10:24:47 by mhoyer           ###   ########.fr       */
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
		exit(msg_error("Error : Bad alloc"));
	pip->fd_pipe = malloc(sizeof(int *) * (pip->nb_cmd - 1));
	if (!pip->fd_pipe)
	{
		free(pip->pid);
		exit(msg_error("Error : Bad alloc"));
	}
	while (++i < pip->nb_cmd - 1)
	{
		pip->fd_pipe[i] = malloc(sizeof(int) * 2);
		if (!pip->fd_pipe[i])
		{
			free_all(pip, "Error : Bad alloc");
		}
	}
}

int	cmp_here(char *str_to_cmp, char *str_model)
{
	int	i;

	i = 0;
	while (str_to_cmp[i] && str_model[i] && str_to_cmp[i] == str_model[i])
		i++;
	if ((str_to_cmp[i] == '\0' && str_model[i] == '\0')
		|| (str_to_cmp[i] == '\n' && str_model[i] == '\0'))
		return (1);
	return (0);
}

int	here_doc(t_pipex *pip, char *limiter)
{
	char	*mem;
	int		fd;

	pip->if_here_doc = 1;
	pip->limiter = limiter;
	pip->infile = TMP_FILE;
	fd = open(TMP_FILE, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ft_putstr_fd("here_doc> ", 1);
	mem = get_next_line(0, 1);
	while (!cmp_here(mem, pip->limiter))
	{
		ft_putstr_fd("here_doc> ", 1);
		ft_putstr_fd(mem, fd);
		free(mem);
		mem = get_next_line(0, 1);
	}
	get_next_line(0, 0);
	free(mem);
	close(fd);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pip;
	int		i;

	if (ac < 5)
		exit(msg_error("Error : ./pipex needs at least 5 arguments"));
	else if (cmp_here(av[1], "here_doc") && ac < 6)
		exit(msg_error("Error : ./pipex here_doc needs at least 6 arguments"));
	pip.if_here_doc = 0;
	pip.infile = av[1];
	if (cmp_here(av[1], "here_doc") && access(av[1], F_OK) == -1)
		here_doc(&pip, av[2]);
	pip.cmd = NULL;
	pip.all_path = NULL;
	pip.outfile = av[ac - 1];
	pip.nb_cmd = ac - 3 - pip.if_here_doc;
	creat_tab(&pip);
	pip.all_path = get_path(&pip, env);
	i = -1;
	while (++i < pip.nb_cmd)
		ft_lstadd_back(&pip.cmd, ft_lstnew(av[i + 2 + pip.if_here_doc], i));
	pip.first_cmd = pip.cmd;
	pipex(&pip);
	unlink(TMP_FILE);
	free_all(&pip, "");
	return (0);
}
