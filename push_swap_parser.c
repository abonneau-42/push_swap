/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:33:51 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 13:26:22 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int is_include(int *already_seen, int count, int value)
{
	int i;

	i = 0;
		
	while (i < count)
	{
		if (already_seen[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int check_number(char *chr, int *a_values, int *i)
{
	long value;
		
	if (!is_number(chr))
		return (0);
	if (ft_strlen(chr) > 11)
		return (0);
	value = ft_atoi(chr);
	if (value < -2147483648 || value > 2147483647 || is_include(a_values, (*i) - 1, (int)value))
		return (0);
	a_values[(*i) - 1] = (int)value;
	(*i)++;
	return (1);
}

int	push_swap_parser(int argc, char **argv, int *a_values)
{
	int i;
	char **tab;
	
	if (argc == 2)
	{
		i = 1;
		while (argv[i - 1])
			if (!check_number(argv[i - 1], a_values, &i) && free_char_tab(argv))
				return (0);
		free_char_tab(argv);
	}
	else
	{
		i = 1;
		while (i < argc)
			if (!check_number(argv[i], a_values, &i))
				return (0);
	}
	return (1);
}

int	push_swap_pre_parser(t_stack *stack, int argc, char **argv, int **a_values)
{
	char	**tab;
	
	stack->size_a = argc - 1;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (1);
		stack->size_a = count_tab_size(tab);
		*a_values = malloc(sizeof(int) * stack->size_a);
		argv = tab;
	}
	else
		*a_values = malloc(sizeof(int) * stack->size_a);
	if (!*a_values)
		return (1);
	if (!push_swap_parser(argc, argv, *a_values))
	{
		write(2, "Error\n", 6);
		return (2);
	}
	if (stack->size_a < 2)
		return (2);
	return (0);
}
