/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:41:17 by gpladet           #+#    #+#             */
/*   Updated: 2019/11/23 23:14:08 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	if (!lst || !f)
		return (NULL);
	if ((new = (t_list *)malloc(ft_lstsize(lst) * sizeof(t_list))))
	{
		new->content = f(lst->content);
		tmp = new;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(ft_lstnew(lst->content));
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
