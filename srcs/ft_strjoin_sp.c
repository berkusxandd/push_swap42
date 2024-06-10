#include "push_swap.h"
#include "../Libft/libft.h"

char	*ft_strjoin_sp(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	char	*joinstr;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	i = 0;
	joinstr = malloc(sizeof(char) * (s1_size + s2_size) + 2);
	if (!joinstr)
		return (NULL);
	ft_strlcpy(joinstr, s1, s1_size + 1);
	while (i < s2_size)
	{
		joinstr[i + s1_size] = s2[i];
		i++;
	}
	joinstr[s1_size + s2_size] = ' ';
	joinstr[s1_size + s2_size + 1] = '\0';
	return (joinstr);
}
