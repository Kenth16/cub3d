/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:56:40 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/20 17:46:18 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	dest = to;
	source = from;
	if (to == from)
		return (to);
	i = 0;
	while (i < numBytes)
	{
		dest[i] = source[i];
		i++;
	}
	return (to);
}
/*
int main()
{
	char *a = "Hello";
	const char *b = "bonjour";

	ft_memcpy(b, a, 3);

	printf("%s\n", b);

    return 0;
}*/