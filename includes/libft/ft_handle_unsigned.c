/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:42:48 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 18:36:21 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_u(unsigned int n, unsigned int base)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_u(unsigned int n, unsigned int base)
{
	char		*s;
	int			size;
	const char	basevalue[] = "0123456789abcdef";

	size = count_u(n, base);
	s = (char *) malloc ((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[size] = '\0';
	size--;
	while (size >= 0)
	{
		s[size] = basevalue[n % base];
		n = n / base;
		size--;
	}
	return (s);
}

void	ft_putnbr_base_u_fd(unsigned int n, unsigned int base, int fd)
{
	const char	basevalue[] = "0123456789abcdef";

	if (n > base - 1)
	{
		ft_putnbr_base_u_fd(n / base, base, fd);
		ft_putnbr_base_u_fd(n % base, base, fd);
	}
	else
		ft_putchar_fd(basevalue[n], 1);
}

int	ft_putnbr_base_hexa(unsigned long long nb)
{
	const char	basevalue[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (nb > 15)
	{
		count = count + ft_putnbr_base_hexa(nb / 16);
		count = count + ft_putnbr_base_hexa(nb % 16);
	}
	else
	{
		ft_putchar_fd(basevalue[nb], 1);
		count++;
	}
	return (count);
}

int	ft_printp(unsigned long long nb)
{
	int	count;

	count = 0;
	if (!nb)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	count = count + 2;
	count = count + ft_putnbr_base_hexa(nb);
	return (count);
}
