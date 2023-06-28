/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:12:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 12:12:19 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check_type(const char *str, int i)
{
	if (str[i] == '%')
	{
		if (check_carac(str[i + 1]))
			return (str[i + 1]);
		if ((str[i + 1] == '+' || str[i + 1] == ' ')
			&& (str[i + 2] == 'd' || str[i + 2] == 'i'))
		{
			return (str[i + 1]);
		}
	}
	return (0);
}

int	aff_bonus(int t, va_list p, char type)
{
	int	nb;

	if (type == '+' || type == ' ')
	{
		nb = va_arg(p, int);
		if (nb >= 0)
		{
			ft_putchar_fd(type, 1);
			t++;
		}
		t += case_all(ft_itoa(nb));
	}
	return (t);
}

int	aff_3(int t, va_list p, char type)
{
	unsigned long	adresse;
	char			*hexa;

	hexa = "0123456789abcdef";
	if (type == 'p')
	{
		adresse = (unsigned long)va_arg(p, void *);
		if (adresse != 0)
		{
			ft_putstr_fd("0x", 1);
			t += 2;
			t += case_all(ft_conv_b_l(adresse, hexa));
		}
		else
		{
			ft_putstr_fd("(nil)", 1);
			t += 5;
		}
	}
	else
		t = aff_bonus(t, p, type);
	return (t);
}

int	aff_p2(int t, va_list p, char type)
{
	char	*hexa;
	char	*hexaup;

	hexa = "0123456789abcdef";
	hexaup = "0123456789ABCDEF";
	if (type == 'u')
		t += case_all(ft_itoa_u(va_arg(p, unsigned int)));
	else if (type == 'x')
		t += case_all(ft_conv_b(va_arg(p, unsigned int), hexa));
	else if (type == 'X')
		t += case_all(ft_conv_b(va_arg(p, unsigned int), hexaup));
	else if (type == 'd' || type == 'i' )
				t += case_all(ft_itoa(va_arg(p, int)));
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		t++;
	}
	else
		t = aff_3(t, p, type);
	return (t);
}

int	aff(const char *chaine, int t, va_list p)
{
	int		i;
	char	type;

	i = -1;
	while (chaine[++i])
	{
		type = check_type(chaine, i);
		if (check_carac(type) || check_carac_bonus(type))
		{
			if (type == 'c')
				t += case_c(va_arg(p, int));
			else if (type == 's')
				t += case_s(va_arg(p, char *));
			else
				t = aff_p2(t, p, type);
			if (check_carac(type))
				i++;
			else
				i += 2;
		}
		else
			ft_putchar_fd(chaine[i], 1);
	}
	va_end(p);
	return (t);
}
