/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:18:20 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 18:16:06 by mitadic          ###   ########.fr       */
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

int	go_do_op_dual(t_list **stk_a, t_list **stk_b, char *instr)
{
	if (ft_strncmp(instr, "ss\n", 4) == 0)
	{
		op_swp(stk_a);
		op_swp(stk_b);
	}
	else if (ft_strncmp(instr, "rr\n", 4) == 0)
	{
		op_rot(stk_a);
		op_rot(stk_b);
	}
	else if (ft_strncmp(instr, "rrr\n", 5) == 0)
	{
		op_revrot(stk_a);
		op_revrot(stk_b);
	}
	else
		return (0);
	return (1);
}

int	go_do_op(t_list **stk_a, t_list **stk_b, char *instr)
{
	if (ft_strncmp(instr, "sa\n", 4) == 0)
		op_swp(stk_a);
	else if (ft_strncmp(instr, "sb\n", 4) == 0)
		op_swp(stk_b);
	else if (ft_strncmp(instr, "ra\n", 4) == 0)
		op_rot(stk_a);
	else if (ft_strncmp(instr, "rb\n", 4) == 0)
		op_rot(stk_b);
	else if (ft_strncmp(instr, "pa\n", 4) == 0)
		op_psh(stk_b, stk_a);
	else if (ft_strncmp(instr, "pb\n", 4) == 0)
		op_psh(stk_a, stk_b);
	else if (ft_strncmp(instr, "rra\n", 5) == 0)
		op_revrot(stk_a);
	else if (ft_strncmp(instr, "rrb\n", 5) == 0)
		op_revrot(stk_b);
	else if (go_do_op_dual(stk_a, stk_b, instr))
		;
	else
		return (0);
	return (1);
}

int	go_sorting(int *arr_raw, char *instrset, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	char	instr[5];
	int		i;
	int		j;

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
	else
		return (clearstk(&stk_a, &stk_b, 1));
}
