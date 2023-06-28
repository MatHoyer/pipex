/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:15:23 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 12:15:24 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	case_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	case_s(char *str)
{
	int	taille;

	if (!str)
		str = "(null)";
	taille = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (taille);
}

int	case_all(char *str)
{
	int	taille;

	if (!str)
		str = "(null)";
	taille = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (taille);
}
