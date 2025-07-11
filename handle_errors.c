/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:31:59 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 09:49:26 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *nbr)
{
	if (!((*nbr >= '0' && *nbr <= '9') || (*nbr == '-' || *nbr == '+')))
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
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack | !*stack)
		return ;
	current = *stack;
	while (current->prev)
		current = current->prev;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error(t_stack_node **stack, char **argv, int is_split)
{
	free_stack(stack);
	if (is_split)
		free_argv(argv);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
