#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
		return (1);
	i = -1;
	while (argv[1][++i])
	{
		if (!(ft_isdigit(argv[1][i])))
			return (1);
	}
	return (0);
}
