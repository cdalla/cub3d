/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 13:55:54 by cdalla-s      #+#    #+#                 */
/*   Updated: 2022/12/16 13:55:55 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*element;

	if (!lst)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	element = new_lst;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&element, ft_lstnew(f(lst->content)));
		if (!element)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		element = element->next;
		lst = lst->next;
	}
	return (new_lst);
}
