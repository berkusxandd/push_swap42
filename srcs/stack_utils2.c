#include "push_swap.h"

int get_value_index(t_node *stack, long value)
{
	int i;
	t_node *tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->nbr == value)
			return i;
		tmp = tmp->next;
		i++;
	}
	return i;
}

t_node *get_node_w_value(t_node *stack, long value)
{
	t_node *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr == value)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
