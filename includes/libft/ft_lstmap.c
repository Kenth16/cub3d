/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:57:02 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/22 18:08:37 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy_f;
	t_list	*new_node;

	cpy_f = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&cpy_f, del);
			return (NULL);
		}
		ft_lstadd_back(&cpy_f, new_node);
		if (cpy_f == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (cpy_f);
}
