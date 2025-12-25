/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrain <lrain@students.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:47:03 by lrain             #+#    #+#             */
/*   Updated: 2025/12/25 19:11:02 by lrain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_full_list	newlst;
	t_list		*temp;

	if (!lst || !f)
		return (NULL);
	newlst = (t_full_list){0};
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&newlst.end, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst.end, temp);
		if (!newlst.start)
			newlst.start = newlst.end;
		newlst.len++;
		if (newlst.len > 1)
			newlst.end = newlst.end->next;
		lst = lst->next;
	}
	return (newlst.start);
}
