/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:21 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/22 18:10:53 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t				i;
	unsigned char		*pnt;

	pnt = pointer;
	i = 0;
	while (i < count)
	{
		pnt[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
/*
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);

    ft_memset(str + 9, 'a', 8);

    printf("After memset():  %s", str);
    return 0;
}*/
