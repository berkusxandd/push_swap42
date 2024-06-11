#include "push_swap.h"

void sort_basic(t_node **stack)
{
	if ((*stack)->nbr == find_max(*stack)->nbr)
	{
		if (ft_stlast(*stack)->nbr == find_min(*stack)->nbr)
		{
			swap(stack,'a');
			r_rotate(stack,'a',1);
		}
		else
			rotate(stack,'a',1);
	}
	else if (ft_stlast(*stack)->nbr == find_max(*stack)->nbr)
		swap(stack,'a');
	else
	{
		if (find_min(*stack)->nbr == (*stack)->nbr)
		{
			r_rotate(stack,'a',1);
			swap(stack,'a');
		}
		else
			r_rotate(stack,'a',1);
	}
}

t_node *get_cheapest_ab(t_node **stack_a)
{
	t_node *tmp_a;
	int cheapest;
	t_node *cheapest_node;
	cheapest = INT_MAX;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->cost < cheapest)
		{
			cheapest = tmp_a->cost;
			cheapest_node = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	return cheapest_node;
}
#include <stdio.h>
void sort_stacks(t_node **stack_a)
{
	t_node *stack_b;

	stack_b = NULL;
	if (stack_len(*stack_a) > 3)
		push(&stack_b,stack_a,'b');
	if (stack_len(*stack_a) > 3)
		push(&stack_b,stack_a,'b');
	while (stack_len(*stack_a) > 3)
	{
		prepare_stacks(stack_a, &stack_b);
		push_smart_ab(stack_a,&stack_b,get_cheapest_ab(stack_a));
	}
	sort_basic(stack_a);
	while (stack_len(stack_b) > 0)
	{
		set_targets_for_b(stack_a,&stack_b);
		push_smart_ba(stack_a,&stack_b,get_node_w_value(*stack_a, stack_b->target_value));
	}
	put_node_top(stack_a, find_min(*stack_a),'a');
}
