/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:09 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/16 17:32:35 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t				i;
	const unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < size)
	{
		if (str[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char s[] = {0, 1, 2, 3, 4, 5};
    printf("\nBefore (): %s\n", s);

    char *a = ft_memchr(s, 0, 1);

    printf("After ():  %s", a);
    return (0);
}*/