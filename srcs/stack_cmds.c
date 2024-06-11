#include "push_swap.h"

void rotate(t_node **stack, char s, int is_print)
{
    t_node *last_node;
    if (!*stack || !(*stack)->next)
		return ;
    last_node = find_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
    last_node->next->next = NULL;
	if (is_print == 0)
		return;
	if (s == 'a')
		ft_putstr_fd("ra\n",1);
	if (s == 'b')
		ft_putstr_fd("rb\n",1);
}

void r_rotate(t_node **stack, char s, int is_print)
{
    t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	if (is_print == 0)
		return;
	if (s == 'a')
		ft_putstr_fd("rra\n",1);
	if (s == 'b')
		ft_putstr_fd("rrb\n",1);
}

void	swap(t_node **stack, char s)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	if (s == 'a')
		ft_putstr_fd("sa\n",1);
	if (s == 'b')
		ft_putstr_fd("sb\n",1);
}
void	push(t_node **dst, t_node **src,char s)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	if (s == 'a')
		ft_putstr_fd("pa\n",1);
	if (s == 'b')
		ft_putstr_fd("pb\n",1);
}
