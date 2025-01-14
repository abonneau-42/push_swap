/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:30:04 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 03:11:06 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_tab(char **char_tab, int size)
{
	while (size--)
		free(char_tab[size]);
	free(char_tab);
	return (NULL);
}

int	word_count(char *s, char c)
{
	int word = 0;

	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s && *s != c)
				*s++;
		}
		else
			*s++;
	}
	return (word);
}

char *strndup(char *str, size_t n)
{
	char *newstr;

	newstr = malloc(sizeof(char) * (n + 1));
	if (!newstr)
		return (NULL);
	newstr[n] = '\0';
	while (n--)
		newstr[n] = str[n];
	return (newstr);
}

char	**ft_split(const char *s, char c)
{
	char **tab;
	int	i = 0;
	int j = 0;
	
	tab = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			tab[j] = strndup((char *)s, i);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
			s = s + i;
		}
		else
			*s++;
	}
	tab[j] = NULL;
	return (tab);
}
