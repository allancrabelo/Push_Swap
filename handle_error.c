/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:31:59 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/12 17:54:32 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//filtro: string vazia, apenas sinal, nao numericos, espaco no meio do numero, multiplo sinal, fora dos limites
int	syntax_error(char *nbr)
{
		if (!((*nbr >= '0' && *nbr <= '9') || (!(*nbr == '-' || *nbr == '+'))))
			return (1);
		if ((*nbr == '-' || *nbr == '+') && !(nbr[1] >= '0' && nbr[1] <= '9'))
			return (1);
		while (*++nbr)
		{
			if (!(*nbr >= '0' && *nbr <= '9'))
				return (1);
		}
		return (0);
}
int	duplicate_check(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	
	if (!stack || !(*stack))
		return ;
	while(*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	error(t_stack_node **stack)
{
	free_stack(stack);
	write (1, "Error\n", 6);
	exit(EXIT_FAILURE);
}


