/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:56:07 by mhamidi           #+#    #+#             */
/*   Updated: 2024/12/04 17:05:34 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	count(int n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		n = -n;
		nb++;
	}
	while (n > 0)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}*/
int	count(long n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		n = -n;
		nb++;
	}
	while (n > 0)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

char	*ft_itoa2(long n)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = count(n);
	p = calloc(sizeof(char), (size + 1));
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		p[size - 1 - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	p[size] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*a;
	long		q;

	if (n == 0)
	{
		a = malloc(2 * sizeof(char));
		if (!a)
			return (NULL);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	q = n;
	a = ft_itoa2(q);
	return (a);
}
/*
int main(void)
{
	char	*a;

	a = ft_itoa(-2147483648);
	printf("%s\n", a);
	return (0);
}*/