/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:19:28 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 01:33:38 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long			result;

	i = 0;
	result = 0;
	sign = 1;

	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((result * 10 + nptr[i] - '0') / 10 != result)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		result = result * 10 + nptr[i++] - '0';
	}
	return (result * sign);
}
