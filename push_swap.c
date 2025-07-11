/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:42:22 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 21:39:09 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	main_helper(t_stack *a, t_stack *b)
{
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
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
	{
		nb[0] = argc;
		a = parse_args(argc, argv + 1, nb);
	}
	b = NULL;
	return (main_helper(a, b));
}
