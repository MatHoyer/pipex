/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:02:24 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 08:02:25 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_carac_bonus(char c)
{
	if (c == ' ' || c == '+')
		return (1);
	return (0);
}

int	check_carac(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	calc_taille_chaine(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && check_carac(str[i + 1]))
			i += 2;
		else if (str[i] == '%'
			&& check_carac_bonus(str[i + 1]) && check_carac(str[i + 2]))
			i += 3;
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			taille_print;
	va_list		arg;

	va_start(arg, str);
	taille_print = calc_taille_chaine(str);
	taille_print = aff(str, taille_print, arg);
	va_end(arg);
	return (taille_print);
}
