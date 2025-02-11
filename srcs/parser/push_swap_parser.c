/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:33:51 by abonneau          #+#    #+#             */
/*   Updated: 2025/02/11 15:57:58 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_include(int *already_seen, int count, int value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (already_seen[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	check_number(char *chr, int *a_values, int *i)
{
	long	value;

	if (!is_number(chr))
		return (0);
	if (ft_strlen(chr) > 11)
		return (0);
	value = ft_atoi(chr);
	if (value < -2147483648 || value > 2147483647
		|| is_include(a_values, (*i) - 1, (int)value))
		return (0);
	a_values[(*i) - 1] = (int)value;
	(*i)++;
	return (1);
}

int	push_swap_parser(int argc, char **argv, int *a_values)
{
	int		i;

	i = 1;
	if (argc == 2)
	{
		while (argv[i - 1])
			if (!check_number(argv[i - 1], a_values, &i) && free_char_tab(argv))
				return (0);
		free_char_tab(argv);
	}
	else
		while (i < argc)
			if (!*argv[i] || !check_number(argv[i], a_values, &i))
				return (0);
	return (1);
}

int	allocate_and_parse(t_stack *stack, int argc, char **argv, int **a_values)
{
	size_t	i;

	i = 0;
	*a_values = malloc(sizeof(int) * stack->size_a);
	if (!*a_values)
	{
		if (argc == 2)
			free_char_tab(argv);
		return (MALOC_FAILURE);
	}
	if (!push_swap_parser(argc, argv, *a_values))
	{
		write(2, "Error\n", 6);
		free(*a_values);
		return (ARGS_NOT_VALID);
	}
	while (i < stack->size_a - 1)
	{
		if ((*a_values)[i] > (*a_values)[i + 1])
			return (VALID_PARAMS);
		i++;
	}
	free(*a_values);
	return (ALREADY_SORTED);
}

int	push_swap_pre_parser(t_stack *stack, int argc, char **argv, int **a_values)
{
	char	**tab;

	if (argc < 2)
		return (ARGS_NOT_VALID);
	stack->size_a = argc - 1;
	if (argc == 2)
	{
		if (!*argv[1])
		{
			write(2, "Error\n", 6);
			return (ARGS_NOT_VALID);
		}
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (1);
		stack->size_a = count_tab_size(tab);
		argv = tab;
	}
	return (allocate_and_parse(stack, argc, argv, a_values));
}
