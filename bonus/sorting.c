/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:18:20 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 16:40:25 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

/*
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
*/

int	go_do_op(t_list **stk_a, t_list **stk_b, char *instr)
{
	if (ft_strncmp(instr, "sa\n", 4) == 0)
		op_swp(stk_a);
	else if (ft_strncmp(instr, "sb\n", 4) == 0)
		op_swp(stk_b);
	else if (ft_strncmp(instr, "ss\n", 4) == 0)
	{
		op_swp(stk_a);
		op_swp(stk_b);
	}
	else if (ft_strncmp(instr, "ra\n", 4) == 0)
		op_rot(stk_a);
	else if (ft_strncmp(instr, "rb\n", 4) == 0)
		op_rot(stk_b);
	else if (ft_strncmp(instr, "rr\n", 4) == 0)
	{
		op_rot(stk_a);
		op_rot(stk_b);
	}
	else if (ft_strncmp(instr, "pa\n", 4) == 0)
		op_psh(stk_b, stk_a);
	else if (ft_strncmp(instr, "pb\n", 4) == 0)
		op_psh(stk_a, stk_b);
	else if (ft_strncmp(instr, "rra\n", 5) == 0)
		op_revrot(stk_a);
	else if (ft_strncmp(instr, "rrb\n", 5) == 0)
		op_revrot(stk_b);
	else if (ft_strncmp(instr, "rrr\n", 5) == 0)
	{
		op_revrot(stk_a);
		op_revrot(stk_b);
	}
	else
		return (0);
	return (1);
}

int	go_sorting(int *arr_raw, char *instrset, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	char	instr[5];
	int	i;
	int	j;

	stk_a = init_stk(arr_raw, size);
	stk_b = NULL;
	if (!stk_a || !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	i = 0;
	while (instrset[i])
	{
		j = -1;
		while (instrset[i] != 0 && instrset[i] != 10)
			instr[++j] = instrset[i++];
		instr[++j] = instrset[i++];
		instr[++j] = 0;
		go_do_op(&stk_a, &stk_b, instr);
	}
	if (stk_b || isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	else //else if (!stk_b && !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 1));
}
	// vl.size = size;
	// vl.smol = -1;
	// vl.step = 0;
	// while (++vl.smol < size)
	// {
	// 	vl.next = vl.smol;
	// 	if (vl.smol < (size - 1))
	// 		vl.next = (vl.smol + 1);
	// 	find_n_swap(arr_ind, &vl, &stk_a, &stk_b);
	// 	if (!stk_b && !isunsorted(stk_a, INT_MAX))
	// 		break ;
	// }
	//	return (clearstk(&stk_a, &stk_b, 1));
	// }
