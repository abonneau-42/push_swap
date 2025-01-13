/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bidir_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:47 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 17:09:48 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_bidir_list(t_list **a, char **value, size_t size_a)
{
	int	i;
	
	i = 0;
	while (i < size_a)
	{
		a[i] = malloc(sizeof(t_list));
		if (!a[i++])
			return (0);
	}
	i = 0;
	a[i]->value = ft_atoi(value[i + 1]);
	a[i]->prev = a[size_a - 1];
	a[i]->next = a[i + 1];
	i++;
	while (i < size_a - 1)
	{
		a[i]->value = ft_atoi(value[i + 1]);
		a[i]->prev = a[i - 1];
		a[i]->next = a[i + 1];
		i++;
	}
	a[i]->value = ft_atoi(value[i + 1]);
	a[i]->prev = a[i - 1];
	a[i]->next = a[0];
	return (1);
}
