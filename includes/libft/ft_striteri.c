/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:40:12 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/17 16:18:46 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
void	fab(unsigned int index, char *character)
{
		if (character[index] == 'A')
		{
			character[index] = 'B';
		}
}

int	main(void)
{
	char str[] = "ARTHRAUUUUUR";

	printf("%s\n", str);

	ft_striteri(str, fab);
	printf("%s\n", str);
	return (0);
}*/