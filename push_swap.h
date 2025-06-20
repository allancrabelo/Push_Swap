/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:02:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/20 18:42:27 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
#include <limits.h>

typedef struct	s_stack_node
{
	int					nbr;//numero da pilha
	int					index;// posicao do numero para saber qual menor e maior
	int					push_cost;// custo para mover para algum lugar
	bool				above_median;// se estiver acima da mediana da pilha
	bool				cheapest;//marca o menor custo da operacao
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;

}	t_stack_node;

//Moviments
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrr(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);


//Algorithm
void	sort_three(t_stack_node **a);

//Utils
bool			sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node **stack);
t_stack_node	*find_min(t_stack_node **stack);

//Handle Errors
void	error(t_stack_node **stack);
void	free_stack(t_stack_node **stack);
int		duplicate_check(t_stack_node *stack, int n);
int		syntax_error(char *nbr);

//Others
char	**ft_split(char *string, char character);
long	ft_atol(char *str);


void	init_stack_a (t_stack_node **a, char **argv);
void	append_node(t_stack_node **stack, int n);

t_stack_node	*find_last(t_stack_node *stack);
#endif
