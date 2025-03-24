/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:01 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/19 18:32:40 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (const char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (const char)c)
		return ((char *)(str + i));
	return (NULL);
}
/*
int	main(void)
{
	char *a = "tripouille";
	char *b;
	char *c;

	b = strchr(a, 't');
	printf("%s\n", b);
	c = ft_strchr(a, 't');
	printf("%s\n", c);
	return (0);
}*/