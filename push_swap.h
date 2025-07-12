/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:02:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 17:18:57 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_stack_node
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
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **b, t_stack_node **a, int print);

//Algorithm
void			sort_three(t_stack_node **a);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);

//Utils
bool			sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
int				ft_max(int a, int b);

//Handle Errors
void			error(t_stack_node **stack, char **argv, int is_split);
void			free_stack(t_stack_node **stack);
int				duplicate_check(t_stack_node *stack, int n);
int				syntax_error(char *nbr);
void			free_argv(char **argv);

//Node inicialzation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			current_index(t_stack_node *stack);

//Init Stack
void			init_stack_a(t_stack_node **a, char **argv, int is_split);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			move_to_top(t_stack_node **stack,
					t_stack_node *node_for_top,
					char stack_name);

//Sort
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			rev_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);

//Others
char			**ft_split(char *string, char character);
long			ft_atol(char *str);
t_stack_node	*find_last(t_stack_node *stack);

#endif
