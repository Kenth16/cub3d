/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navarre <navarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:14 by mhamidi           #+#    #+#             */
/*   Updated: 2024/10/08 12:06:49 by navarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>

int	main(void)
{
	char	c;

	c = 'f';
	int	 b;
	int	 a;
	a = isalpha(c);
	b = alphabet(c);
	printf("%d\n", b);
	printf("%d\n", a);
}
*/
