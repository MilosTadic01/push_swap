/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds_steps_a1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:51:21 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 18:26:18 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conds_steps_a_a(t_list **stk_a)
{
	op_revrot(stk_a);
	op_swp(stk_a);
	ft_printf("rra\nsa\n");
}

void	conds_steps_a_b(t_list **stk_a)
{
	op_rot(stk_a);
	ft_printf("ra\n");
}

void	conds_steps_a_c(t_list **stk_a)
{
	op_swp(stk_a);
	ft_printf("sa\n");
}

void	conds_steps_a_d(t_list **stk_a)
{
	op_swp(stk_a);
	op_rot(stk_a);
	ft_printf("sa\nra\n");
}

void	conds_steps_a_e(t_list **stk_a, t_list **stk_b)
{
	op_psh(stk_a, stk_b);
	op_rot(stk_a);
	ft_printf("pb\nra\n");
}
