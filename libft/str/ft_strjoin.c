/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:09:30 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 12:09:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*conc;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	conc = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (conc == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		conc[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		conc[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	conc[i] = '\0';
	return (conc);
}
