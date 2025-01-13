/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_bidir_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:05:17 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 19:00:32 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_bidir_front(t_list **top, int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = value;
	if (!(*top))
	{
		new->next = new;
		new->prev = new;
		*top = new;
		return ;
	}
	new->next = *top;
	new->prev = (*top)->prev;
	(*top)->prev->next = new;
	(*top)->prev = new;
	*top = new;
}
