#include "push_swap.h"

void rotate(t_node **stack)
{
    t_node *last_node;
    if (!*stack || !(*stack)->next)
		return ;
    last_node = ft_stlast(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    last_node->next->next = NULL;
}

void r_rotate(t_node **stack)
{
    t_node *last_node;
    t_node *tmp;
    if (!*stack || !(*stack)->next)
		return ;

    last_node = ft_stlast(*stack);
    last_node->next = (*stack)->next;
    tmp = *stack;
    *stack = last_node;
    last_node = ft_stlast(*stack);
    last_node->next = tmp;
}