/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:39:55 by afahs             #+#    #+#             */
/*   Updated: 2025/06/23 09:11:01 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//tool[0] = chunk_max ; tool[1] = rotations ; tool[2] = size_a ;
static void	push_chunks_helper(t_stack **a, t_stack **b,
	int *tools, int chunk_size)
{
	if ((*a)->index <= tools[1])
	{
		pb(a, b);
		tools[0]++;
		if (stack_size(*b) > 1 && (*b)->index < tools[1] - chunk_size / 2)
			rb(b);
	}
	else
	{
		ra(a);
		tools[2]++;
	}
	if (tools[2] >= tools[3])
	{
		tools[1] += chunk_size;
		tools[0] = 0;
		tools[2] = 0;
	}
	if (tools[0] == chunk_size)
	{
		tools[1] += chunk_size;
		tools[0] = 0;
	}
}

void	push_chunks(t_stack **a, t_stack **b, int chnk_sz)
{
	int	*tools;

	tools = malloc(sizeof(int) * 4);
	if (!tools)
		return ;
	tools[0] = 0;
	tools[1] = chnk_sz;
	while (stack_size(*a) > 3)
	{
		tools[2] = 0;
		tools[3] = stack_size(*a);
		push_chunks_helper(a, b, tools, chnk_sz);
	}
	free(tools);
}

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	assign_index(*stack_a, size);
	if (size <= 100)
		chunk_size = 20;
	else if (size <= 500)
		chunk_size = 45;
	else
		chunk_size = 75;
	push_chunks(stack_a, stack_b, chunk_size);
	while (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3)
	{
		push_init(stack_a, stack_b);
		while (*stack_b)
		{
			get_target_position(stack_a, stack_b);
			get_cost(stack_a, stack_b);
			do_cheapest_move(stack_a, stack_b);
		}
		if (!is_sorted(*stack_a))
			shift_stack(stack_a);
	}
}
