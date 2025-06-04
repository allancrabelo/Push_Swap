/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:15:28 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/04 17:26:01 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int	value;
	struct	s_stack	*next;
}	t_stack;

int	ft_atoi(const char *str);
t_stack	*stack_new(int	n);
void	stack_addback(t_stack **head, t_stack *new_node);
void	stack_free(t_stack **head);
int	ft_error(int exit);

// DELETE
void test(t_stack *stack_a, t_stack *stack_b);

#endif

