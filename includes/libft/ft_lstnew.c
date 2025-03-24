/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:52 by mhamidi           #+#    #+#             */
/*   Updated: 2024/12/03 18:23:46 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = ft_strdup(content);
	if (new_elem->content == NULL)
	{
		free(new_elem);
		new_elem = NULL;
		return (NULL);
	}
	new_elem->next = NULL;
	free(content);
	return (new_elem);
}
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;*/