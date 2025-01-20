/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:07:23 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/20 20:22:07 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**free_char_tab(char **char_tab)
{
	int i;

	i = 0;
	while (char_tab[i])
		free(char_tab[i++]);
	free(char_tab);
}

int	count_tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

long ft_abs(int number)
{
	if (number < 0)
		return (number * (-1));
	return (number);
}

int ft_min(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

int ft_max(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}