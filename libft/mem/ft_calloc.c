/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:07:29 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/03 11:07:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*a_return;
	int			over;

	over = (int)(size * nmemb);
	if (size)
	{
		if (nmemb != (size_t)over / size)
			return (NULL);
	}
	a_return = malloc(nmemb * size);
	if (a_return == NULL)
		return (NULL);
	ft_bzero(a_return, nmemb * size);
	return (a_return);
}
