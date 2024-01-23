/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/22 18:04:10 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*set_list(char **argv, int size)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = (int *)malloc(size * sizeof(int));
	while (argv[1][i])
	{
		if (ft_iswhite(argv[1][i])) // this is just handled by atoi, throw it out?
			i++;
		else
		{
			arr[j] = ft_atoi(argv[1][i]);
			while (argv[1][i] && ft_isdigit(argv[1][i]))
				i++;
		}
	}
}


t_list	*get_list_size(char **argv)
{
	int	i;
	int	size;
	t_list	*lst;

	i = 0;
	size = 0;
	while (argv[1][i])
	{
		if (ft_iswhite(argv[1][i]))
			i++;
		else
		{
			while (argv[1][i] && ft_isdigit(argv[1][i]))
				i++;
			size++;
		}
	}
	lst = set_list(argv, size);
	return (lst);
}

int	input_valid(char **argv)
{
	int		i;
	char	c;

	i = -1;
	while (argv[1][++i])
	{
		c = argv[1][++i];
		if (!(ft_isdigit(c) || ft_iswhite(c)) || ((c == 43 || \
				c == 45) && !(ft_isdigit(argv[1][i + 1]))))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (!input_valid(argv))
		return (1);
	printf("Should be 0\n");
	return (0);
}
