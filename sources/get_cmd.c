/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:20:45 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/28 15:16:06 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_good_path(t_list *cmd, char **path)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], cmd->split[0]);
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK | X_OK) != -1)
		{
			free_mat(path);
			return (tmp);
		}
		free(tmp);
	}
	return (NULL);
}

int	get_cmd(t_list *cmd, char **path)
{
	cmd->split = ft_split(cmd->content, ' ');
	cmd->path = get_good_path(cmd, path);
	if (!cmd->path)
		return (1);
	return (0);
}