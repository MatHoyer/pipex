/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:07:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/12 09:07:40 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	creat(unsigned long nb, unsigned int taille)
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

static char	*rev_tab(char *str, int taille)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < taille / 2)
	{
		tmp = str[taille - 1 - i];
		str[taille - 1 - i] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_conv_b_l(unsigned long nb, char *base_to)
{
	int			i;
	char		*str;
	int			taille;

	i = 0;
	taille = ft_strlen(base_to);
	str = malloc(creat(nb, taille) + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[i++] = base_to[0];
	while (nb > 0)
	{
		str[i] = base_to[(nb % taille)];
		i++;
		nb = nb / taille;
	}
	str[i] = '\0';
	return (rev_tab(str, ft_strlen(str)));
}
