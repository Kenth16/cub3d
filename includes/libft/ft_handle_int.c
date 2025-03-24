/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:26:45 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 18:35:53 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int base, int fd)
{
	const char	basevalue[] = "0123456789abcdef";

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n > base - 1)
	{
		ft_putnbr_base_fd(n / base, base, fd);
		ft_putnbr_base_fd(n % base, base, fd);
	}
	else
		ft_putchar_fd(basevalue[n], 1);
}

static int	count(int n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, int base)
{
	char		*s;
	int			size;
	const char	basevalue[] = "0123456789abcdef";

	size = count(n, base);
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
