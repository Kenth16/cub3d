/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:22:20 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/20 19:17:12 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	is_whitespace(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;
	while (s1[start] != '\0' && is_whitespace(s1[start], set) == 1)
		start++;
	while (end > start && is_whitespace(s1[end - 1], set) == 1)
		end--;
	len = end - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s1 + start, len);
	str[len] = '\0';
	return (str);
}
/*
int main(void)
{
	const char *a = "  ";
	const char *set = " x";

	//printf("%s",a);
	char *b = ft_strtrim(a, set);
	printf("%s", b);
	return (0);
}*/