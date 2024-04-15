/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:21:53 by pierre            #+#    #+#             */
/*   Updated: 2024/04/15 00:21:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	**og;

	og = &lst;
	new = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	ft_lstclear(og, del);
	return (new);
}
