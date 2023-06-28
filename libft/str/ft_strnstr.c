/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:50 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 10:45:52 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)&big[0]);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (ft_strlen(little) == j)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
	printf("%s", ft_strnstr( "aaabcabcd", "abcd", 9));
	return 0;
}*/
