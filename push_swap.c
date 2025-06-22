/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:18:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/22 17:16:41 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
 	t_stack_node	*a;// pilha original que sera ordenada
	t_stack_node	*b;// pilha incial vazia
	
	a = NULL;// zero as pilhas
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2) 
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if(!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 4)
			sort_four(&a, &b);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	return (0);
}
