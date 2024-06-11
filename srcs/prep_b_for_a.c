#include "push_swap.h"

void set_targets_for_b(t_node **stack_a, t_node **stack_b)
{

	long			target_value;
	t_node *tmp_b;
	t_node *tmp_a;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		 target_value = LONG_MAX;
		 tmp_a = *stack_a;
		 while (tmp_a)
		 {
		 	if (tmp_a->nbr > tmp_b->nbr && tmp_a->nbr < target_value)
		 		target_value = tmp_a->nbr;
		 	tmp_a = tmp_a->next;
		 }
		 if (target_value == LONG_MAX)
		 	target_value = find_min(*stack_a)->nbr;
		tmp_b->target_value = target_value;
		tmp_b = tmp_b->next;
	}
}

void push_smart_ba(t_node **stack_a, t_node **stack_b)
{
	put_node_top(stack_a, get_node_w_value(*stack_a, (*stack_b)->target_value),'a');
	push(stack_a,stack_b,'a');
}
