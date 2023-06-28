/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:37:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 11:37:23 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		str = malloc(1);
	else if (ft_strlen(s) - start <= len)
		str = malloc(ft_strlen(s) - start + 1);
	else
		str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start + i])
		{
			str[i] = s[i + start];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
