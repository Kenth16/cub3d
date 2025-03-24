/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:46:35 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/20 18:39:06 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (const char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *a = "je suis mehdi";
	char *b;
	char *c;

	b = strrchr(a, 'j');
	printf("%s\n", b);
	c = ft_strrchr(a, 'j');
	printf("%s\n", c);
	return (0);
}*/