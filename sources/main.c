/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:18:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/28 14:12:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_pipex *pip)
{
	int	i;

	i = 0;
	while(i < pip->nb_cmd)
	{
		wait(NULL);
		i++;
	}
}

int main(int ac, char **av, char **env)
{
	t_pipex	pipex_mem;
	int		i;

	if (ac < 5)
		exit(msg_error("Error : ./pipex needs at least 5 arguments"));
	pipex_mem.cmd = NULL;
	pipex_mem.infile = av[1];
	pipex_mem.outfile = av[ac - 1];
	pipex_mem.nb_cmd = ac - 3;
	i = -1;
	while (++i < pipex_mem.nb_cmd)
		ft_lstadd_back(&pipex_mem.cmd, ft_lstnew(av[i + 2]));
	pipex(&pipex_mem, env);
	wait_all(&pipex_mem);
	free_all(&pipex_mem, "");
	return (0);
}
