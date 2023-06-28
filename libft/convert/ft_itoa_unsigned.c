/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:43:11 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 11:43:14 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	calcul_alloc(long n, char **str, int i)
{
	int	count;
	int	tot;

	count = 0;
	tot = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	tot += count;
	if (i == 1)
	{
		ft_bzero(*str, tot + 1);
		tot--;
	}
	return (tot);
}

char	*ft_itoa_u(unsigned int n)
{
	int		i;
	long	nb;
	char	*str;

	nb = n;
	i = calcul_alloc(nb, &str, 0);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = calcul_alloc(nb, &str, 1);
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int main(int ac, char **av)
// {
// 	char *res = ft_itoa(ft_atoi(av[1]));
// 	ft_print_result(res);
// 	free(res);
// }
