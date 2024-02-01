/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conds_steps_a2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:34:27 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 17:37:40 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conds_steps_a_f(t_list **stk_a)
{
	op_revrot(stk_a);
	op_revrot(stk_a);
	op_swp(stk_a);
	ft_printf("rra\nrra\nsa\n");
}

void	conds_steps_a_g(t_list **stk_a)
{
	op_revrot(stk_a);
	ft_printf("rra\n");
}

void	conds_steps_a_h(t_list **stk_a, t_list **stk_b)
{
	op_psh(stk_a, stk_b);
	ft_printf("pb\n");
}
