/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:30:06 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 21:55:08 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*s) || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_stack **a, int i)
{
	swap_stack(a);
	if (i)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	swap_stack(b);
	if (i)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int i)
{
	swap_stack(a);
	swap_stack(b);
	if (i)
		write(1, "ss\n", 3);
}
