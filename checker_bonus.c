/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:19:57 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/12 14:55:41 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	command(t_stack_node *a, t_stack_node *b, char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		return (sa(&a, 0));
	if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		return (sb(&b, 0));
	if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (ss(&a, &b, 0));
	if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		return (ra(&a, 0));
	if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		return (rb(&b, 0));
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (rr(&a, &b, 0));
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		return (rra(&a, 0));
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		return (rrb(&b, 0));
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		return (rrr(&a, &b, 0));
	if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		return (pa(&a, &b, 0));
	if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		return (pb(&a, &b, 0));
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	parser(t_stack_node *a, t_stack_node *b)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		command(a, b, line);
		free(line);
	}
	if (sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	get_next_line(-1);
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
