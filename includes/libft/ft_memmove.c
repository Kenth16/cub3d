/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:55 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/20 20:14:52 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	i = 0;
	dest = to;
	source = from;
	if (source > dest)
	{
		while (i < numBytes)
		{
			dest[i] = source[i];
			i++;
		}
	}
	i = numBytes;
	if (dest > source)
	{
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	return (to);
}
/*
int main()
{
	char *a = "Hello";
	char *b = malloc(100);

	ft_memmove(b, a, 3);

	printf("%s\n", b);

    return 0;
}*/