/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds_steps_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:49:53 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 17:57:11 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conds_steps_b_f(t_list **stk_b)
{
	op_revrot(stk_b);
	ft_printf("rrb\n");
}

void	conds_steps_b_g(t_list **stk_b)
{
	op_rot(stk_b);
	ft_printf("rb\n");
}
