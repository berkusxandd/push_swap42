#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
#include <stdlib.h>
typedef struct s_node
{
	long	nbr;
	struct s_node	*next;
}			t_node;

void print_stack(t_node *stack); //POUR DEBUG!!!!! 

long		ft_atol(const char *str);
char	*ft_strjoin_sp(char const *s1, char const *s2);
t_node *ft_stlast(t_node *stack);
void	ft_stadd_back(t_node **stack, t_node *stack_new);
t_node	*ft_stnew(char *str);
void free_stack(t_node **node);
void free_tab(char **tab);
int	check_arg(char **av);

int	stack_len(t_node *stack);
t_node	*find_min(t_node *stack);
int	stack_sorted(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_last(t_node *stack);
void rotate(t_node **stack);
void r_rotate(t_node **stack);
#endif
