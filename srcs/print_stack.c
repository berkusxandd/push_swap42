#include "push_swap.h"
#include <stdio.h>
void print_stack(t_node *stack)
{
    t_node *tmp;
    tmp = stack;
    while(tmp != NULL)
    {
        printf("%ld\n", tmp->nbr);
        tmp = tmp->next;
    }
}