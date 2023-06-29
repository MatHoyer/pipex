/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:57:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nv_list;
	t_list	*nv;

	nv_list = NULL;
	while (lst)
	{
		nv = ft_lstnew((*f)(lst->content), 0);
		ft_lstadd_back(&nv_list, nv);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (nv_list);
}
