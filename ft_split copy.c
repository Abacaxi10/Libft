/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:30:26 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/08 20:08:53 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	fill_tab(char *str, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
}

static void	set_tab(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		count = 0;
		while (s[j + count] && s[j + count] != c)
			count++;
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + j), c);
			i++;
			j = j + count;
		}
		else
			j++;
	}
	tab[i] = NULL;
}

static int	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;

	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	set_tab(tab, s, c);
	return (tab);
}
/*
#include <stdio.h>

int	main()
{
	int	i;
	char **tab;
	char *str;

	i = 0;
	str = "Salut,, ,,Ma,,,,Biche,fjieir423847324,,,,,,,,,";
	tab = ft_split(str, ',');

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
