/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:30:31 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 18:36:40 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handlechar(va_list ap, int *count)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	*count = *count + 1;
}

void	handlestring(va_list ap, int *count)
{
	char	*a;

	a = va_arg(ap, char *);
	if (a == NULL)
		a = "(null)";
	ft_putstr_fd(a, 1);
	*count = *count + ft_strlen(a);
}

void	handleinteger(va_list ap, int *count)
{
	int		a;
	char	*s;

	a = va_arg(ap, int);
	ft_putnbr_base_fd(a, 10, 1);
	s = ft_itoa(a);
	*count = *count + ft_strlen(s);
	free(s);
}

void	handleunsignedint(va_list ap, int *count)
{
	char			*s;
	unsigned int	a;

	a = va_arg(ap, unsigned int);
	ft_putnbr_base_u_fd(a, 10, 1);
	s = ft_itoa_base_u(a, 10);
	*count = *count + ft_strlen(s);
	free(s);
}

void	handlehex(va_list ap, char c, int *count)
{
	char			*s;
	int				i;
	unsigned int	a;

	a = va_arg(ap, unsigned int);
	if (c == 'x')
	{
		ft_putnbr_base_u_fd(a, 16, 1);
		s = ft_itoa_base_u(a, 16);
		*count = *count + ft_strlen(s);
		free(s);
	}
	else if (c == 'X')
	{
		s = ft_itoa_base_u(a, 16);
		i = 0;
		while (s[i] != '\0')
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
		ft_putstr_fd(s, 1);
		*count = *count + ft_strlen(s);
		free(s);
	}
}
