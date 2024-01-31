/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 18:30:23 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conds_b_weigh(t_op *op, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	if (op->pos_smol > op->pos_last / 2)
	{
		while (++i <= (op->pos_last - op->pos_smol))
			conds_steps_b_f(stk_b);
	}
	else
	{
		while (++i < op->pos_smol)
			conds_steps_b_g(stk_b);
	}
	conds_steps_b_a(stk_a, stk_b);
}

void	conds_a_weigh(t_op *op, int *step, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	if (*step == 0 && op->pos_smol > op->pos_last / 2)
	{
		while (++i < (op->pos_last - op->pos_smol))
			conds_steps_a_g(stk_a);
	}
	else
	{
		while (++i < op->pos_smol)
			conds_steps_a_h(stk_a, stk_b);
		conds_steps_a_b(stk_a);
	}
}

int	conds_if_b(t_op *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
		conds_steps_b_a(stk_a, stk_b);
	else if (op->pos_smol == 1)
	{
		if (op->pos_next == 0)
			conds_steps_b_b(stk_a, stk_b);
		else if (op->pos_next == 2)
			conds_steps_b_c(stk_a, stk_b);
		else
			conds_steps_b_c(stk_a, stk_b);
	}
	else if (op->pos_smol == op->pos_last)
		conds_steps_b_d(stk_a, stk_b);
	else if (op->pos_smol == (op->pos_last - 1))
		conds_steps_b_e(stk_a, stk_b);
	else
	{
		++(*step);
		return (0);
	}
	return (++(*step));
}

void	c_a_exp(t_op *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_next == 0)
	{
		if (*step == 0 && !(*stk_b) && \
			!isunsorted((*stk_a)->next->next, INT_MAX))
			conds_steps_a_c(stk_a);
		else
			conds_steps_a_d(stk_a);
	}
	else if (!(*stk_b) && !isunsorted((*stk_a)->next, INT_MAX))
		conds_steps_a_b(stk_a);
	else
		conds_steps_a_e(stk_a, stk_b);
}

int	conds_if_a(t_op *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
	{
		if (op->pos_next == op->pos_last && \
			!isunsorted((*stk_a)->next, op->pos_last - 1 - 1))
			conds_steps_a_a(stk_a);
		else
			conds_steps_a_b(stk_a);
	}
	else if (op->pos_smol == 1)
		c_a_exp(op, step, stk_a, stk_b);
	else if (*step == 0 && op->pos_next == (op->pos_last - 1) && \
			op->pos_smol == (op->pos_last) && \
			!isunsorted(*stk_a, op->pos_last - 2))
		conds_steps_a_f(stk_a);
	else if (op->pos_smol == op->pos_last)
		;
	else if (*step == 0 && op->pos_smol == (op->pos_last - 1))
		conds_steps_a_g(stk_a);
	else
	{
		++(*step);
		return (0);
	}
	return (++(*step));
}
