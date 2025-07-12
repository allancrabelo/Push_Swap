/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:18:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 17:20:06 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parser(t_stack_node *a, t_stack_node *b)
{
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 4)
			sort_four(&a, &b);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split;
	char			**args;
	int				is_split;

	a = NULL;
	b = NULL;
	split = NULL;
	is_split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		args = split;
		is_split = 1;
	}
	else
		args = argv + 1;
	init_stack_a(&a, args, is_split);
	parser(a, b);
	free_stack(&a);
	if (split)
		free_argv(split);
}
