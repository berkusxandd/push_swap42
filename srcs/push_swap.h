#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
#include <stdlib.h>
#include <limits.h>
typedef struct s_node
{
	long	nbr;
	struct s_node	*next;
	struct s_node	*prev;
	long	target_value;
	int cost;
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
int get_value_index(t_node *stack, long value);
void rotate(t_node **stack,char s, int is_print);
void r_rotate(t_node **stack, char s, int is_print);
void	swap(t_node **stack, char s);
t_node	*find_one_before_last(t_node *stack);
void	push(t_node **dst, t_node **src, char s);
void sort_basic(t_node **stack);
void sort_stacks(t_node **stack_a);
void prepare_stacks(t_node **stack_a, t_node **stack_b);
void push_smart_ab(t_node **stack_a, t_node **stack_b, t_node *cheapest);
t_node  *get_node_w_value(t_node *stack, long value);
void set_targets_for_b(t_node **stack_a, t_node **stack_b);
void push_smart_ba(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void put_node_top(t_node **stack, t_node *node, char s);
t_node *get_cheapest_ab(t_node **stack_a);
#endif
