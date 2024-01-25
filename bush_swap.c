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

void	free_arrays(int *arr_raw, int *arr_ind)
{
	if (arr_raw)
	{
		free (arr_raw);
		arr_raw = NULL;
	}
	if (arr_ind)
	{
		free (arr_ind);
		arr_ind = NULL;
	}
	return ;
}

t_list	*init_stk(int *arr, int size)
{
	int	i;
	t_list	*head;

	i = -1;
	head = NULL;
	while (++i < size)
		ft_lstadd_back(head, ft_lstnew(arr[i]));
	return (head);
}

void	find_n_swap(int smol, int size, t_list **stk_a, t_list **stk_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int	next;

	next = smol;	//	<-- just shorter for me to write 'else' this way
	if (smol < (size - 1))
		next = (smol + 1);
	//
	if (smol == (int)(*stk_a)->content)
		op_rot(*stk_a);
	else if (smol == (int)(*stk_b)->next->content)

}

int	go_sorting(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	int	smol;

	stk_a = init_stk(arr_raw, size);
	if (!stk_a)
		return (0);
	stk_b = NULL;
	smol = -1;
	while (++smol < size)
		find_n_swap(arr_ind[smol], size, &stk_a, &stk_b);
	return (1);
}
	


void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	buff;
	int	swap;

	if (!arr)
		return ;
	swap = 1;
	while (swap == 1)
	{
		i = -1;
		swap = 0;
		while (++i < (size - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
				swap = 1;
			}
		}
	}
}


int	*index_arr(int *arr_raw, int size)
{
	int	i;
	int	buff;
	int	*arr_ind;

	i = -1;
	arr_ind = (int *)malloc(sizeof(int) * size);
	if (!arr_ind)
	{
		free (arr_raw);
		return (NULL);
	}
	while (++i < size)
		arr_ind[i] = arr_raw[i];
	ft_bubble_sort(arr_ind, size);
	return (arr_ind);
}


int	*handle_input(char **argv, int size)
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
	return (arr_raw);
}


int	get_size(char **argv)
{
	int	i;
	int	size;

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
	return (size);
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
	int	size;
	int	*arr_raw;
	int	*arr_ind;

	if (error || !input_valid(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	size = get_size(argv);
	arr_raw = handle_input(argv, size);
	if (!arr_raw)
		return (2);
	arr_ind = index_arr(arr_raw, size);
	if (!arr_ind)
		return (2);
	if (!go_sorting(arr_raw, arr_ind, size))
	{
		free_arrays(arr_raw, arr_ind);
		return (3);
	}
	return (0);
}

// So Homework: give members of int * to linked-list contents, then see what
// happens when you change the values.


// ultimately how to check the next smallest
i++;
smallest = arr_ind[i];
// that's it bby; that's why we make that presorted arr_ind
