#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
#include <stdlib.h>
typedef struct s_node
{
	long	nbr;
	struct s_node	*next;
}			t_node;

long		ft_atol(const char *str);
char	*ft_strjoin_sp(char const *s1, char const *s2);
t_node *ft_stlast(t_node *stack);
void	ft_stadd_back(t_node **stack, t_node *stack_new);
t_node	*ft_stnew(char *str);
void free_stack(t_node **node);
void free_tab(char **tab);
int	check_arg(char **av);
#endif
