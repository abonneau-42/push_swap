/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:52:15 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:56:42 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_abs(int number)
{
	if (number < 0)
		return (number * (-1));
	return (number);
}

int	ft_min(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

int	ft_max(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}
