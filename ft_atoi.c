/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:19:28 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 15:20:27 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	get_sign(const char *nptr, int *i)
{
	if (nptr[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long			result;

	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = get_sign(nptr, &i);
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
