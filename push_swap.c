/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:42:22 by afahs             #+#    #+#             */
/*   Updated: 2025/06/29 06:58:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	print_stack(t_stack *stack, char *name)
// {
// 	printf("Stack %s: ", name);
// 	if (!stack)
// 	{
// 		printf("(empty)\n");
// 		return ;
// 	}
// 	while (stack)
// 	{
// 		printf("[%d]", stack->value);
// 		if (stack->next)
// 			printf(" -> ");
// 		stack = stack->next;
// 	}
// 	printf(" -> NULL\n");
// }

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
