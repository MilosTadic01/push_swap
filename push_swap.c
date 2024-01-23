/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/23 18:36:14 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// ultimately how to check the next smallest
i++;
smallest = arr_ind[i];
// that's it bby; that's why we make that presorted arr_ind

int	*index_arr(int *arr_raw, int size)
{
	int	i;
	int	smol;
	int	*arr_ind;

	i = -1;
	arr_ind = (int *)malloc(sizeof(int) * size);
	while (++i < size)
	{
		if (i > 0 && arr_raw) 
		arr_ind[i] = arr_raw[i]
}

// Heed this: maybe we don't even need two arrays! If we just linked-list to the
// unsorted values, because that's what we need, then the linked list is pointing
// to value, right? Ok, we need to play around with linked list first, before
// we decide how many int arrays and which function is returning what.
//
// So Homework: give members of int * to linked-list contents, then see what
// happens when you change the values.

int	*conv_n_index(char **argv, int size)
{
	int	i;
	int	j;
	int	*arr_raw;

	i = 0;
	j = 0;
	arr_raw = (int *)malloc(size * sizeof(int));
	if (!arr_raw)
		return (NULL);
	while (argv[1][i])
	{
		if (ft_iswhite(argv[1][i]))
			i++;
		else
		{
			arr_raw[j] = ft_atoi(&argv[1][i]);
			while (argv[1][i] && ft_isdigit(argv[1][i]))
				i++;
			j++;
		}
	}
	return (index_arr(arr_raw, size));
}


void	work_list(char **argv)
{
	int	i;
	int	size;
	char	*arr_ind;
	// t_list	*lst;

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
	arr_ind = conv_n_index(argv, size);
	// lst = set_list(argv, size);
	// return (lst);
}

int	input_valid(char **argv)
{
	int		i;
	char	c;

	i = -1;
	while (argv[1][++i])
	{
		c = argv[1][i];
		if (!(ft_isdigit(c) || ft_iswhite(c)) || ((c == 43 || \
				c == 45) && !(ft_isdigit(argv[1][i + 1]))))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !input_valid(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	work_list(argv);
	printf("Should be 0\n");
	return (0);
}
