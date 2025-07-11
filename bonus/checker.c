/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:49:15 by afahs             #+#    #+#             */
/*   Updated: 2025/07/05 02:19:06 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	apply_helper(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(op, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(op, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rb"))
		rb(b, 0);
}

static int	apply_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")
		|| !ft_strcmp(op, "pa") || !ft_strcmp(op, "pb") || !ft_strcmp(op, "ra")
		|| !ft_strcmp(op, "rb"))
		apply_helper(a, b, op);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b, 0);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int	main_helper_two(t_stack *a, t_stack *b)
{
	if (!a)
	{
		write(2, "Error\n", 6);
		free_stack(b);
		return (1);
	}
	if (b != NULL)
	{
		write(1, "KO\n", 3);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (is_sorted(a))
	{
		write(1, "OK\n", 3);
		free_stack(a);
		return (0);
	}
	write(1, "KO\n", 3);
	free_stack(a);
	return (0);
}

static int	main_helper(t_stack *a, t_stack *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		if (!apply_op(&a, &b, op))
		{
			free(op);
			free_stack(a);
			free_stack(b);
			return (1);
		}
		free(op);
	}
	return (main_helper_two(a, b));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**v;
	int		nb[1];

	nb[0] = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		v = ft_split(argv, ' ', nb);
		a = parse_args(argc, v, nb);
		free_split(v, nb);
	}
	else
		a = parse_args(argc, argv + 1, &argc);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	return (main_helper(a, b));
}
