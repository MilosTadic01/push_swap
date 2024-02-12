/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:37:07 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:12:16 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upto3_ifpos0(t_list **stk_a, t_list **stk_b)
{
	op_psh(stk_a, stk_b, 'b');
	op_swp(stk_a, 'a');
	op_psh(stk_b, stk_a, 'a');
}

void	upto3_ifpos1(int nxt, t_list **stk_a)
{
	if (nxt == 0)
		op_swp(stk_a, 'a');
	else
		op_rot(stk_a, 'a');
}

void	upto3_ifpos2(int nxt, t_list **stk_a)
{
	if (nxt == 0)
		op_revrot(stk_a, 'a');
	else
	{
		op_swp(stk_a, 'a');
		op_revrot(stk_a, 'a');
	}
}

void	sort_upto3(int *arr_ind, int size, t_list **stk_a, t_list **stk_b)
{
	int	pos;
	int	nxt;

	if (!isunsorted(*stk_a, size))
		return ;
	pos = ft_lstintpos(*stk_a, arr_ind[0]);
	nxt = ft_lstintpos(*stk_a, arr_ind[1]);
	if (pos == 0)
		upto3_ifpos0(stk_a, stk_b);
	else if (pos == 1)
		upto3_ifpos1(nxt, stk_a);
	else if (pos == 2)
		upto3_ifpos2(nxt, stk_a);
}

