/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:21:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:17:48 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmp_str(char *str_to_cmp, char *str_model)
{
	int	i;

	i = 0;
	while (str_to_cmp[i] && i < 5 && str_to_cmp[i] == str_model[i])
		i++;
	if (str_to_cmp[i] == str_model[i])
		return (1);
	return (0);
}

int	str_len_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		i++;
	}
	return (i);
}

char	*find_path(char *str)
{
	char	cmp[6];
	int		i;

	i = -1;
	while (++ i < 5 && str[i])
		cmp[i] = str[i];
	cmp[i] = '\0';
	if (cmp_str(cmp, "PATH="))
		return (&str[i]);
	return (NULL);
}

char	**put_slash(char **path)
{
	int		i;
	char	**a_return;

	i = -1;
	a_return = ft_calloc(sizeof(char *), (size_t)(str_len_mat(path) + 1));
	if (!a_return)
		return (NULL);
	while (path[++i])
	{
		a_return[i] = ft_strjoin(path[i], "/");
		free(path[i]);
	}
	a_return[i] = NULL;
	free(path);
	return (a_return);
}

char	**get_path(char **env)
{
	char	**path;
	int		i;
	char	*mem_path;

	if (!env || !*env)
	{
		return (NULL);
	}
	i = -1;
	mem_path = 0;
	while (env[++i] && !mem_path)
	{
		mem_path = find_path(env[i]);
	}
	path = ft_split(mem_path, ':');
	return (put_slash(path));
}
