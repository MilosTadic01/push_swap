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

int	buffover(const char *nptr)
{
	long long	l;
	int		minus;
	
	l = 0;
	minus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			minus = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		l += *nptr - 48;
		l *= 10;
		nptr++;
	}
	l = l / 10 * minus;
	if (l > INT_MAX || l < INT_MIN)
		return (1);
	return (0);
}

void	*free_arrays(int *arr_raw, int *arr_ind)
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
	return (NULL);
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

void	conds_if_b(op_data *op, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
	{
		op_psh(*stk_b, *stk_a);
		op_rot(*stk_b);
	}
	else if (op->pos_smol == 1)
	{
		if (op->pos_next == 0)
		{
			op_swp(*stk_b);
			op_psh(*stk_b, *stk_a);
			op_rot(*stk_a);
		}
		else
		{
			op_rot(*stk_b);
			op_psh(*stk_b, *stk_a);
			op_rot(*stk_a);
		}
	}
	else if (op->pos_smol == op->last)
	{
		op_revrot(*stk_b);
		op_psh(*stk_b, *stk_a);
		op_rot(*stk_a);
	}
	else if (op->pos_smol == (op->last - 1)) // note: can happen more often
	{
		op_revrot(*stk_b);
		op_revrot(*stk_b);
		op_psh(*stk_b, *stk_a);
		op_rot(*stk_a);
	}
	else
	{
		*step++;
		return (0);
	}
	return (*step++);
}

void	conds_if_a(op_data *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
		op_rot(*stk_a);
	else if (op->pos_smol == 1)
	{
		if (op->pos_next == 0)
		{
			op_swp(*stk_a);
			op_rot(*stk_a);
		}
		else
		{
			op_psh(*stk_a, *stk_b);
			op_rot(*stk_a);
		}
	}
	else if (op->pos_smol == op->last)
		;
	else if (*step == 0 && op->pos_smol == (op->last - 1)) // note: may only happen if 1st step
		op_revrot(*stk_a);
	else
	{
		*step++;
		return (0);
	}
	return (*step++);
}

void	find_n_swap(int *arr_ind, vl_data *vl, t_list **stk_a, t_list **stk_b)
{
	static int	step = 0;
	op_data	op;

	op.pos_smol = ft_lstintpos(*stk_a, arr_ind[vl->smol]);
	if (op.pos_smol == -1)
		op.pos_smol = ft_lstintpos(*stk_b, arr_ind[vl->smol]);
	op.pos_next = ft_lstintpos(*stk_a, arr_ind[vl->next]);
	if (op.pos_next == -1)
		op.pos_next = ft_lstintpos(*stk_b, arr_ind[vl->next]);
	op.pos_last = vl->size - 1;
	if (" is in b ") // how
	{
		if (!conds_if_b(&op, &step, *stk_a, *stk_b))
			conds_b_weigh(&op, &step, *stk_a, *stk_b);
	}
	else
	{
		if (!conds_if_a(&op, &step, *stk_a, *stk_b))
			conds_a_weigh(&op, &step, *stk_a, *stk_b);
	}
}

int	go_sorting(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	vl_data	vl;

	stk_a = init_stk(arr_raw, size);
	if (!stk_a)
		return (0);
	stk_b = NULL;
	vl.size = size;
	vl.smol = -1;
	while (++vl.smol < size)
	{
		vl.next = vl.smol; // <-- just more space-efficient for me to write 'else' this way
		if (vl.smol < (vl.size - 1))
			vl.next = (vl.smol + 1);
		find_n_swap(arr_ind, &vl, &stk_a, &stk_b);
	}
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
			if (buffover(argv[1][i])
				return (free_arrays(arr_raw, NULL);
			arr_raw[j] = ft_atoi(argv[1][i]); // <-- was '&argv' b4. Why. Don't.
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

	if (argc != 2 || !input_valid(argv))
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
		arr_raw = free_arrays(arr_raw, arr_ind);
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
