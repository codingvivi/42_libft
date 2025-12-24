/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:47:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/24 20:13:24 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new0;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	lst = lst->next;
	new0 = head;
	while (lst)
	{
		node = ft_lstnew(f(lst));
		if (!node)
		{
			ft_lstclear(&new0, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		head = head->next;
		lst = lst->next;
	}
	return (new0);
}
