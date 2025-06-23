/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:28 by afahs             #+#    #+#             */
/*   Updated: 2025/06/23 08:07:01 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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
void	sa(t_stack	**stack_a);
void	sb(t_stack	**stack_b);
void	ss(t_stack	**stack_a,	t_stack	**stack_b);
void	pa(t_stack	**stack_a,	t_stack	**stack_b);
void	pb(t_stack	**stack_a,	t_stack	**stack_b);
void	ra(t_stack	**stack_a);
void	rb(t_stack	**stack_b);
void	rr(t_stack	**stack_a,	t_stack	**stack_b);
void	rra(t_stack	**stack_a);
void	rrb(t_stack	**stack_b);
void	rrr(t_stack	**stack_a,	t_stack	**stack_b);

// stack_utils.c
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack	**stack,	t_stack	*new);
t_stack	*stack_get_last(t_stack	*stack);
int		stack_size(t_stack	*stack);
void	free_stack(t_stack	**stack);

// sort_utls.c
void	push_chunks(t_stack **stk_a, t_stack **stk_b, int chnk_sz);
void	sort_three(t_stack	**stack);
void	sort(t_stack	**stack_a,	t_stack	**stack_b);

// position_utils.c
void	assign_index(t_stack	*stack_a, int stack_size);
void	get_position(t_stack	**stack);
void	get_target_position(t_stack	**stack_a,	t_stack	**stack_b);
void	get_cost(t_stack	**stack_a,	t_stack	**stack_b);

// move_utils.c
void	do_cheapest_move(t_stack	**stack_a,	t_stack	**stack_b);

// check_utils.c
int		is_number(char	*str);
int		has_duplicates(t_stack	*stack);
t_stack	*parse_args(int c, char **v);

// random_utils.c
int		is_sorted(t_stack	*stack);
long	int	ft_atoi(const	char	*str);
int		abs_value(int n);
void	shift_stack(t_stack	**stack_a);

#endif