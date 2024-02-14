/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:03:27 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:30:37 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_belowmid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while (*(int *)(*stk_a)->content >= arr_ind[0])
		{
			rotcount++;
			op_rot(stk_a, 'a');
		}
		if ((*(int *)(*stk_a)->content < arr_ind[0]))
			op_psh(stk_a, stk_b, 'b');
	}
	while (rotcount-- > 0)
		op_revrot(stk_a, 'a');
}

void	flip_a(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b)
{
	int	mid;
	int	restsz;

	mid = chunksz / 2;
	restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		if (isunsorted(*stk_a, 2))
			op_swp(stk_a, 'a');
		return ;
	}
	if (!isunsorted(*stk_a, chunksz))
		return ;
	pb_belowmid(&arr_ind[mid], mid, stk_a, stk_b);
	flip_a(&arr_ind[mid], restsz, stk_a, stk_b);
	flip_b(arr_ind, mid, stk_a, stk_b);
}
