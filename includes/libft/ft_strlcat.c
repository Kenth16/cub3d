/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:57:00 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/19 12:46:32 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (dst[a] && a < size)
		a++;
	while (src[i] && size && i + a < size - 1)
	{
		dst[a + i] = src[i];
		i++;
	}
	if (a < size)
		dst[a + i] = '\0';
	while (src[i])
		i++;
	return (i + a);
}
