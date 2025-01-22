/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bidir_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:47 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 17:03:45 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_bidir_list(t_list **a, int *a_values, size_t size_a)
{
	size_t	i;

	i = 0;
	while (i < size_a)
	{
		a[i] = malloc(sizeof(t_list));
		if (!a[i++])
			return (0);
	}
	i = 0;
	a[i]->value = a_values[i];
	a[i]->prev = a[size_a - 1];
	a[i]->next = a[i + 1];
	i++;
	while (i < size_a - 1)
	{
		a[i]->value = a_values[i];
		a[i]->prev = a[i - 1];
		a[i]->next = a[i + 1];
		i++;
	}
	a[i]->value = a_values[i];
	a[i]->prev = a[i - 1];
	a[i]->next = a[0];
	return (1);
}
