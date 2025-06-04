/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:05:50 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/04 17:28:30 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/////////////// lists
t_stack *init_stack(int argc, char **argv)
{
	t_stack	*head;
	t_stack *new_node;
	int	i;

	i = 0;	
	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	while (i < argc)
	{
		new_node = stack_new(ft_atoi(argv[i]));//fazer atol
		if (!new_node)
		{
			stack_free(&head);
			return (NULL);
		}
		stack_addback(&head, new_node);
		i++;
	}
	
	return (head);
}

t_stack	*stack_new(int	n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	return (node);
}

void	stack_addback(t_stack **head, t_stack *new_node)
{
	t_stack *temp;

	if(!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return ;
}

void	stack_free(t_stack **head)
{
	t_stack *temp;
	t_stack *current;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(*head);
	return ;
}

/////////////////// exe
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
int	ft_error(int exit)
{
	write(2, "Error\n", 6);
	return (exit);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (ft_error(0));
// Add argc == 2 to use ftsplit
	stack_a = init_stack(argc, argv);
	if	(!stack_a)
		return (ft_error(1));
	stack_b = init_stack(1, argv);
	if	(!stack_b)
		return (ft_error(1));
	test(stack_a, stack_b);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}

