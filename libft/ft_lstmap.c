/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:00:39 by abibi             #+#    #+#             */
/*   Updated: 2020/05/12 15:08:33 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buf;
	t_list	*el;

	if (!lst || !f || !del)
		return ((t_list *)0);
	buf = (t_list*)0;
	while (lst)
	{
		el = ft_lstnew((*f)(lst->content));
		if (el)
			ft_lstadd_back(&buf, el);
		else
		{
			ft_lstclear(&buf, del);
			return ((t_list*)0);
		}
		lst = lst->next;
	}
	return (buf);
}
