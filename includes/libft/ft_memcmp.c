/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:29:04 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/19 12:38:40 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*string1;
	unsigned const char	*string2;
	size_t				i;

	i = 0;
	string1 = s1;
	string2 = s2;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = memcmp(0, 0, 1);
	printf("%d\n", a);
	b = ft_memcmp(0, 0, 1);
	printf("%d\n", b);
	return (0);
}*/