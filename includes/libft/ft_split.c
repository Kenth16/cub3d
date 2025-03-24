/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:13:02 by mhamidi           #+#    #+#             */
/*   Updated: 2024/12/03 17:55:28 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static	int	strlen_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

char	**ft_split2(char const *s, char c)
{
	int		taille;
	char	**tableau;

	if (!s)
		return (0);
	taille = count_words(s, c) + 1;
	tableau = (char **) malloc (sizeof(char *) * taille);
	if (!tableau)
		return (0);
	return (tableau);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		j;
	int		i;

	t = ft_split2(s, c);
	if (!t)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			t[j] = (char *)malloc(sizeof(char) * (strlen_sep(s + i, c) + 1));
			if (!t[j])
				return (free_tab(t));
			ft_strlcpy(t[j], (char *)s + i, strlen_sep(s + i, c) + 1);
			i = i + strlen_sep(s + i, c);
			j++;
		}
		else
			i++;
	}
	t[j] = NULL;
	return (t);
}
