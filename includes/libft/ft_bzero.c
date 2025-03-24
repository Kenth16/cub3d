/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:21:25 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/16 14:49:18 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	size_t			i;
	unsigned char	*pnt;

	pnt = pointer;
	i = 0;
	while (i < count)
	{
		pnt[i] = '\0';
		i++;
	}
}
/*
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore ft_bezo(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    bzero(str + 3,8);

    printf("After ft_bezo():  %s", str);
    return 0;
}*/