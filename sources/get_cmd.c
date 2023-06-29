/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:19:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:19:54 by mhoyer           ###   ########.fr       */
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
