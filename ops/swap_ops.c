/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:30:06 by afahs             #+#    #+#             */
/*   Updated: 2025/06/23 05:48:45 by afahs            ###   ########.fr       */
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

void	sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
