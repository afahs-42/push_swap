/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:28 by afahs             #+#    #+#             */
/*   Updated: 2025/07/05 02:19:16 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "gnl/gnl.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// /ops
void	sa(t_stack	**stack_a, int i);
void	sb(t_stack	**stack_b, int i);
void	ss(t_stack	**stack_a,	t_stack	**stack_b, int i);
void	pa(t_stack	**stack_a,	t_stack	**stack_b, int i);
void	pb(t_stack	**stack_a,	t_stack	**stack_b, int i);
void	ra(t_stack	**stack_a, int i);
void	rb(t_stack	**stack_b, int i);
void	rr(t_stack	**stack_a,	t_stack	**stack_b, int i);
void	rra(t_stack	**stack_a, int i);
void	rrb(t_stack	**stack_b, int i);
void	rrr(t_stack	**stack_a,	t_stack	**stack_b, int i);
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack	**stack,	t_stack	*new);
t_stack	*stack_get_last(t_stack	*stack);
int		stack_size(t_stack	*stack);
void	free_stack(t_stack	*stack);
void	sort_three(t_stack	**stack);
void	sort(t_stack	**stack_a,	t_stack	**stack_b);
void	assign_index(t_stack	*stack_a, int stack_size);
void	get_position(t_stack	**stack);
void	get_target_position(t_stack	**stack_a,	t_stack	**stack_b);
void	get_cost(t_stack	**stack_a,	t_stack	**stack_b);
void	do_cheapest_move(t_stack	**stack_a,	t_stack	**stack_b);
t_stack	*parse_args(int c, char **v, int *nb);
int		is_sorted(t_stack	*stack);
int		abs_value(int n);
void	shift_stack(t_stack	**stack_a);
void	free_split(char **split, int *nb);
char	**ft_split(char **s, char c, int *nb);
int		ft_strcmp(char *s1, char *s2);

#endif