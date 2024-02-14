/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:03:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:34:57 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_all_engine(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	while (++i < mid)
	{
		if ((*(int *)(*stk_a)->content) < arr_ind[mid])
			op_psh(stk_a, stk_b, 'b');
		else if (*(int *)ft_lstlast(*stk_a)->content < arr_ind[mid])
		{
			op_revrot(stk_a, 'a');
			op_psh(stk_a, stk_b, 'b');
		}
		else
		{
			while ((*(int *)(*stk_a)->content) >= arr_ind[mid])
			{
				op_rot(stk_a, 'a');
			}
			op_psh(stk_a, stk_b, 'b');
		}
	}
}

void	pb_all_check(int *arr_ind, int size, t_list **stk_a, t_list **stk_b)
{
	int	mid;
	int	rest;

	mid = size / 2;
	rest = size - mid;
	if (size <= 2)
	{
		if (isunsorted(*stk_a, 2))
			ft_sortsmall(stk_a);
		return ;
	}
	pb_all_engine(arr_ind, mid, stk_a, stk_b);
	pb_all_check(&arr_ind[mid], rest, stk_a, stk_b);
	flip_b(arr_ind, mid, stk_a, stk_b);
}

int	go_midpointing(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = init_stk(arr_raw, size);
	stk_b = NULL;
	if (!stk_a || !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	if (size <= 3)
		sort_upto3(arr_ind, size, &stk_a, &stk_b);
	else if (size > 3)
		pb_all_check(arr_ind, size, &stk_a, &stk_b);
	return (clearstk(&stk_a, &stk_b, 1));
}
