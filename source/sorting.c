/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:18:20 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/05 17:45:44 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isunsorted(t_list *stk, int end)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < end)
	{
		if (*(int *)stk->content >= *(int *)stk->next->content)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	isntflowing(t_list *stk, int end)
{
	int	i;
	int	seams;

	i = -1;
	seams = 0;
	while (stk && stk->next && ++i < end)
	{
		if (*(int *)stk->content >= *(int *)stk->next->content)
		{
			seams++;
			if (seams > 1)
				return (1);
		}
		stk = stk->next;
	}
	return (0);
}

void	find_n_swap(int *arr_ind, t_vl *vl, t_list **stk_a, t_list **stk_b)
{
	t_op		op;

	op.pos_smol = ft_lstintpos(*stk_a, arr_ind[vl->smol]);
	if (op.pos_smol == -1)
		op.pos_smol = ft_lstintpos(*stk_b, arr_ind[vl->smol]);
	op.pos_next = ft_lstintpos(*stk_a, arr_ind[vl->next]);
	if (op.pos_next == -1)
		op.pos_next = ft_lstintpos(*stk_b, arr_ind[vl->next]);
	if (ft_lstintpos(*stk_a, arr_ind[vl->smol]) != -1)
	{
		op.pos_last = ft_lstsize(*stk_a) - 1;
		if (!conds_if_a(&op, vl, stk_a, stk_b))
			conds_a_weigh(&op, vl, stk_a, stk_b);
	}
	else
	{
		op.pos_last = ft_lstsize(*stk_b) - 1;
		if (!conds_if_b(&op, vl, stk_a, stk_b))
			conds_b_weigh(&op, stk_a, stk_b);
	}
}

int	go_sorting(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	t_vl	vl;

	stk_a = init_stk(arr_raw, size);
	stk_b = NULL;
	if (!stk_a || !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	vl.size = size;
	vl.smol = -1;
	vl.step = 0;
	if (sifting_ok(arr_ind, size, &stk_a, &stk_b))
		return (clearstk(&stk_a, &stk_b, 1));
	while (++vl.smol < size)
	{
		vl.next = vl.smol;
		if (vl.smol < (size - 1))
			vl.next = (vl.smol + 1);
		find_n_swap(arr_ind, &vl, &stk_a, &stk_b);
		if (!stk_b && !isunsorted(stk_a, INT_MAX))
			break ;
	}
	return (clearstk(&stk_a, &stk_b, 1));
}
