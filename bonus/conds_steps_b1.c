/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds_steps_b1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:41:11 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 18:29:19 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conds_steps_b_a(t_list **stk_a, t_list **stk_b)
{
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("pa\nra\n");
}

void	conds_steps_b_b(t_list **stk_a, t_list **stk_b)
{
	op_swp(stk_b);
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("sb\npa\nra\n");
}

void	conds_steps_b_c(t_list **stk_a, t_list **stk_b)
{
	op_rot(stk_b);
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("rb\npa\nra\n");
}

void	conds_steps_b_d(t_list **stk_a, t_list **stk_b)
{
	op_revrot(stk_b);
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("rrb\npa\nra\n");
}

void	conds_steps_b_e(t_list **stk_a, t_list **stk_b)
{
	op_revrot(stk_b);
	op_revrot(stk_b);
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("rrb\nrrb\npa\nra\n");
}
