/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:39:32 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 13:39:34 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	calc_taille_mat(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	calc_taille_mot(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_all(char **mat, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(mat[j]);
		j++;
	}
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ind;
	char	**mat;

	if (!s)
		return (NULL);
	mat = malloc(sizeof(char *) * (size_t)(calc_taille_mat(s, c) + 1));
	if (!mat)
		return (NULL);
	i = 0;
	ind = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			mat[ind++] = ft_substr(s, i, calc_taille_mot(s, c, i) - i);
			if (!mat[ind - 1])
				return (free_all(mat, ind - 1));
			i = calc_taille_mot(s, c, i);
		}
		else
			i++;
	}
	mat[ind] = NULL;
	return (mat);
}
