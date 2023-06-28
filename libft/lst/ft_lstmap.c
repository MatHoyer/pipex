/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/09 15:22:27 by mhoyer           ###   ########.fr       */
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
		nv = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&nv_list, nv);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (nv_list);
}
