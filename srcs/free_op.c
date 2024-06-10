#include "push_swap.h"
#include <stdio.h>
void free_stack(t_node **node)
{
	t_node	*tmp;

	if (!node)
	{
		return ;
	}
	while (*node)
	{
		tmp = (*node)->next;
		(*node)->nbr = 0;
		free(*node);
		*node = tmp;
	}
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return;
	while(tab[i])
		free(tab[i++]);
	free(tab);
}
