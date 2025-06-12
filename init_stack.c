/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:56:18 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/12 18:20:01 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)//quero anexar um node no fim da stack
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	
	if(!stack)
		return;
	node = malloc(sizeof(t_stack_node));
	if(!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a (t_stack_node **a, char **argv)
{
	long	n;//aparentemente so 'e assim por causa de um bit a mais nos limites do int
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error (a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error (a);
		if (duplicate_check(*a, (int)n));
		append_node(a, (int)n);
		i++;
	}	
}
