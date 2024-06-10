#include "push_swap.h"

void	ft_stadd_back(t_node **stack, t_node *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stlast(*stack))->next = stack_new;
}

t_node *ft_stlast(t_node *stack)
{
	if (!stack)
		return NULL;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return stack;
}

t_node	*ft_stnew(char *str)
{
	t_node	*new;
	long nbr;

	nbr = ft_atol(str);
	new = malloc(sizeof (t_node));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}
