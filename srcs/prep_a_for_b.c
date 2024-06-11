#include "push_swap.h"

void rotate_2_for_a(t_node **stack_a, t_node **stack_b)
{
	while ((get_cheapest_ab(stack_a))->target_value != (*stack_b)->nbr)
	{
		rotate(stack_a,'a',0);
		rotate(stack_b,'b',0);
	}
	ft_putstr_fd("rr\n",1);
}

void r_rotate_2_for_a(t_node **stack_a, t_node **stack_b)
{
	while ((get_cheapest_ab(stack_a))->target_value != (*stack_b)->nbr)
	{
		r_rotate(stack_a,'a',0);
		r_rotate(stack_b,'b',0);
	}
	ft_putstr_fd("rrr\n",1);
}

void set_targets_for_a(t_node *stack_a, t_node *stack_b)
{
	t_node *tmp_a;
	t_node *tmp_b;
	long target_value;

	tmp_a = stack_a;
	while (tmp_a)
	{
	target_value = LONG_MIN;
	tmp_b = stack_b;
	while (tmp_b)
	{
		 if (tmp_b->nbr < tmp_a->nbr && tmp_b->nbr > target_value)
		 		target_value = tmp_b->nbr;
		 tmp_b = tmp_b->next;
	}
	 if (target_value == LONG_MIN)
	 		target_value = find_max(stack_b)->nbr;
	tmp_a->target_value = target_value;

	tmp_a = tmp_a->next;
	}
}

void set_costs_for_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;
	t_node *tmp_a;
	int i;

	tmp_a = stack_a;
	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (tmp_a)
	{
		i = get_value_index(stack_a,tmp_a->nbr);
		tmp_a->cost = i;
		if (!(i > (stack_len(stack_a) / 2)))
			tmp_a->cost = len_a - i;
		if (get_value_index(stack_b, tmp_a->target_value) > ((stack_len(stack_b) / 2)))
			tmp_a->cost += len_b - get_value_index(stack_b, tmp_a->target_value);
		else
			tmp_a->cost += (get_value_index(stack_b, tmp_a->target_value));
		tmp_a = tmp_a->next;
	}
}

void put_node_top(t_node **stack, t_node *node,char s)
{
	if (*stack == node)
		return;
	if (get_value_index(*stack, node->nbr) > ((stack_len(*stack) / 2)))
	{
		while ((*stack)->nbr != node->nbr)
			r_rotate(stack, s,1);
	}
	else
	{
		while ((*stack)->nbr != node->nbr)
			rotate(stack, s,1);
	}
}

void push_smart_ab(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	if (get_value_index(*stack_a,cheapest->nbr) > ((stack_len(*stack_a) / 2)) && get_value_index(*stack_b,cheapest->target_value) > ((stack_len(*stack_b) / 2)))
		r_rotate_2_for_a(stack_a,stack_b);
	else if (get_value_index(*stack_a,cheapest->nbr) < ((stack_len(*stack_a) / 2)) && get_value_index(*stack_b,cheapest->target_value) < ((stack_len(*stack_b) / 2)))
		rotate_2_for_a(stack_a,stack_b);
	put_node_top(stack_a,cheapest, 'a');
	put_node_top(stack_b, get_node_w_value(*stack_b, cheapest->target_value),'b');
	push(stack_b,stack_a,'b');
}
void prepare_stacks(t_node **stack_a, t_node **stack_b)
{
	set_targets_for_a(*stack_a, *stack_b);
	set_costs_for_a(*stack_a, *stack_b);
}


