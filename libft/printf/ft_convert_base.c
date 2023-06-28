/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:11:46 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 12:11:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	puiss(long nbr, char *base)
{
	long	result;

	result = ft_strlen(base);
	while (nbr - result > 0)
	{
		result *= ft_strlen(base);
	}
	if (nbr - result != 0)
		return (result / ft_strlen(base));
	else
		return (result);
}

static int	creat(long nb, int taille)
{
	int	i;

	i = 0;
	if (nb < taille)
		return (1);
	while (nb >= taille)
	{
		nb /= taille;
		i++;
	}
	return (i + 1);
}

char	*ft_conv_b(unsigned int nbr, char *base_to)
{
	int			i;
	long		p;
	long		nb;
	char		*str;

	i = 0;
	nb = nbr;
	str = malloc(creat(nb, ft_strlen(base_to)) + 1);
	if (!str)
		return (NULL);
	p = puiss(nb, base_to);
	while (p != 0)
	{
		str[i] = base_to[(nb / p)];
		i++;
		nb = nb % p;
		p /= ft_strlen(base_to);
	}
	str[i] = '\0';
	return (str);
}
