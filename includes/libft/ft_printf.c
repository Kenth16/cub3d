/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:45:54 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 18:36:11 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myfunction(char c, va_list ap, int *count)
{
	if (c == 'c')
		handlechar(ap, count);
	else if (c == 's')
		handlestring(ap, count);
	else if (c == 'd' || c == 'i')
		handleinteger(ap, count);
	else if (c == 'u')
		handleunsignedint(ap, count);
	else if (c == 'x' || c == 'X')
		handlehex(ap, c, count);
	else if (c == '%')
		handlepercent(count);
	else if (c == 'p')
		handlepointer(ap, count);
}

void	handlepercent(int *count)
{
	ft_putchar_fd('%', 1);
	*count = *count + 1;
}

void	handlepointer(va_list ap, int *count)
{
	*count = *count + ft_printp(va_arg(ap, unsigned long long));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		count;

	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start (ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			myfunction(format[i + 1], ap, &count);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
