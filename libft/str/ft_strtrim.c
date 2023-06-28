/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:30:01 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 12:30:02 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		cmp;
	size_t		k;
	char		*cp;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && check_set(s1[i], set))
		i++;
	while (k > i && check_set(s1[k], set))
		k--;
	cp = malloc((k - i) + 2);
	if (!cp)
		return (NULL);
	cmp = i;
	while (s1[i] && j <= k - cmp)
		cp[j++] = s1[i++];
	cp[j] = '\0';
	return (cp);
}

/*
int main()
{
	printf("%s", ft_strtrim("   xxxtripouille   xxx", " x"));
	return 0;
}*/
