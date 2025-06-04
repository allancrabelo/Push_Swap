#include "push_swap.h"
# include <stdio.h> 

void print_stacks_side_by_side(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *node_a = stack_a;
	t_stack *node_b = stack_b;

	printf(" Index | Stack A | Stack B\n");
	printf("-------|---------|--------\n");

	int i = 1;
	while (node_a || node_b)
	{
		printf(" [%3d] | ", i++);

		if (node_a)
		{
			printf("%7d | ", node_a->value);
			node_a = node_a->next;
		}
		else
			printf("%7s | ", "---");

		if (node_b)
		{
			printf("%7d\n", node_b->value);
			node_b = node_b->next;
		}
		else
			printf("%7s\n", "---");
	}
}	

void test(t_stack *stack_a, t_stack *stack_b)
{
	printf("Stack status:\n");
	print_stacks_side_by_side(stack_a, stack_b);
	return ;
}
