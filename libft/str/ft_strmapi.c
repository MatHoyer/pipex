/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:55:20 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/04 08:55:21 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// char	f(unsigned int i, char c)
// {
// 	if (i % 2)
// 		return ('c');
// 	return ('r');
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = -1;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (s[++i])
	{
		str[i] = f(i, str[i]);
	}
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	printf("%s\n", ft_strmapi("bonjour je suis la", &f));
// 	return 0;
// }