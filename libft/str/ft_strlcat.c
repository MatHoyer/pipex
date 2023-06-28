/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:38:41 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 08:38:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		tot;

	if (!dst || !src)
		return (0);
	i = 0;
	j = ft_strlen(dst);
	tot = ft_strlen(src) + ft_strlen(dst);
	if (size == 0 || ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (tot);
}
