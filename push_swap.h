/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:50 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 03:52:49 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int	value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list 	*top_a;
	t_list 	*top_b;
	t_list 	**a;
	t_list 	**b;
	size_t	size_a;
	size_t	size_b;
}	t_stack;

long	ft_atoi(const char *nptr);
int		create_bidir_list(t_list **a, int *a_values, size_t size_a);
void	lstadd_bidir_front(t_list **top, int value);
int 	push_swap_parser(int argc, char **argv, int *a_values);
char	**ft_split(const char *s, char c);
void	**free_char_tab(char **char_tab);
int		count_tab_size(char **tab);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif