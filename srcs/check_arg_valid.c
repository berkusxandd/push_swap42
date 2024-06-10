int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_arg(char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while ((av[i][j] != '\0'))
		{
			if (sign(av[i][j]))
			{
				j++;
				if (!digit(av[i][j]))
					return (0);
			}
			else if (digit(av[i][j]))
			{
				j++;
				if (av[i][j] == '\0')
					break ;
				if (!digit(av[i][j]) && !space(av[i][j]))
					return (0);
			}
			else
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}
