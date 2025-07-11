/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:15:06 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 21:53:49 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_stack(t_stack **s)
{
	t_stack	*last;
	t_stack	*near_last;

	if (!(*s) || !(*s)->next)
		return ;
	last = *s;
	near_last = NULL;
	while (last->next)
	{
		near_last = last;
		last = last->next;
	}
	near_last->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_stack **a, int i)
{
	reverse_rotate_stack(a);
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	reverse_rotate_stack(b);
	if (i)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (i)
		write(1, "rrr\n", 4);
}
