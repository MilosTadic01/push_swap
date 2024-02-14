/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:03:00 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:29:54 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_abovemid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while (*(int *)(*stk_b)->content <= arr_ind[0])
		{
			rotcount++;
			op_rot(stk_b, 'b');
		}
		if ((*(int *)(*stk_b)->content > arr_ind[0]))
			op_psh(stk_b, stk_a, 'a');
	}
	while (rotcount-- > 0)
		op_revrot(stk_b, 'b');
}

void	flip_b_base(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < chunksz)
	{
		while (*(int *)(*stk_b)->content < arr_ind[0])
		{
			rotcount++;
			op_rot(stk_b, 'b');
		}
		if ((*(int *)(*stk_b)->content >= arr_ind[0]))
			op_psh(stk_b, stk_a, 'a');
	}
	while (rotcount-- > 0)
		op_revrot(stk_b, 'b');
	if (isunsorted(*stk_a, 2))
		op_swp(stk_a, 'a');
	return ;
}

void	flip_b(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b)
{
	int	mid;
	int	restsz;
	int	i;

	mid = chunksz / 2;
	i = -1;
	if (chunksz % 2 == 0)
		restsz = chunksz - mid + 1;
	else
		restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		flip_b_base(arr_ind, chunksz, stk_a, stk_b);
		return ;
	}
	else if (!isrevunsorted(*stk_b, chunksz))
	{
		while (++i < chunksz)
			op_psh(stk_b, stk_a, 'a');
		return ;
	}
	pa_abovemid(&arr_ind[mid], chunksz - mid - 1, stk_a, stk_b);
	flip_a(&arr_ind[mid + 1], chunksz - mid - 1, stk_a, stk_b);
	flip_b(arr_ind, restsz, stk_a, stk_b);
}
