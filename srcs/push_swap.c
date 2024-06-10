#include "push_swap.h"
#include <stdio.h>

// void basic_stack_sort(t_node **stack)
// {
// 	t_stack_node	*biggest_node;

// 	biggest_node = find_max(*a);
// 	if (biggest_node == *a)
// 		ra(a, 0);
// 	else if ((*a)->next == biggest_node)
// 		rra(a, 0);
// 	if ((*a)->nbr > (*a)->next->nbr)
// 		sa(a, 0);
// }

int is_value_unique(char **all_nbr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (all_nbr[i])
	{
		j = i + 1;
		while (all_nbr[j])
		{
			if (ft_atol(all_nbr[i]) == ft_atol(all_nbr[j]))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

char	*merge_params(char **av)
{
	char	*all_nbr;
	int		i;
	char	*tmp;

	i = 2;
	all_nbr = ft_strjoin_sp("", av[1]);
	while (av[i] != NULL)
	{
		tmp = all_nbr;
		all_nbr = ft_strjoin_sp(all_nbr, av[i]);
		free(tmp);
		i++;
	}
	return (all_nbr);
}

t_node	*create_stack_a(char **av)
{
	int		i;
	char	*all_params;
	char	**all_nbr;
	t_node	*stack_a;

	i = 1;
	all_params = merge_params(av);
	all_nbr = ft_split(all_params, ' ');
	free(all_params);
	stack_a = ft_stnew(all_nbr[0]);
	while (all_nbr[i] != NULL)
	{
		ft_stadd_back(&stack_a, ft_stnew(all_nbr[i]));
		i++;
	}
	free_tab(all_nbr);
	return (stack_a);
}

int	main(int ac, char **av, char **env)
{
	t_node	*stack_a;

	if (!env || ac < 2)
		return (1);
	if (av[1][0] == '\0' || check_arg(av) == 0)
	{
		ft_putstr_fd("Error\n",2);
		return -1;
	}
	stack_a = create_stack_a(av);
	print_stack(stack_a);
	r_rotate(&stack_a);
	print_stack(stack_a);
	free_stack(&stack_a);
	return (1);
}
