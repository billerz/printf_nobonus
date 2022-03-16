/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatthan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:32:37 by npatthan          #+#    #+#             */
/*   Updated: 2022/02/15 19:33:30 by npatthan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*next_newlst;
	t_list	*next_lst;

	newlst = ft_lstnew((*f)(lst->content));
	if (newlst == NULL)
		return (NULL);
	next_newlst = newlst;
	next_lst = lst->next;
	while (next_lst != NULL)
	{
		next_newlst->next = ft_lstnew((*f)(next_lst->content));
		if (next_newlst->next == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		next_lst = next_lst->next;
		next_newlst = next_newlst->next;
	}
	return (newlst);
}
