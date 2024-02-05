/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sifting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:20:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/05 17:25:58 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_vip_b(t_vip *vp, t_list *stk_b)
{
	vp.sz_b = ft_lstsize(stk_b);
	if (stk_b)
	{
		vp->pb0 = (int)stk_b->content;
		if (stk_b->next)
		{
			vp->pb1 = (int)stk_a->next->content;
			if (stk_b->next->next)
			{
				while (stk_b->next->next)
					stk_b = stk_b->next;
				vp->pbzm1 = stk_b->content;
				vp->pbz = stk_b->next->content;
			}
		}
	}
}
void	init_vip_a(t_vip *vp, t_list *stk_a)
{
	vp.sz_a = ft_lstsize(stk_a);
	if (stk_a)
	{
		vp->pa0 = (int)stk_a->content;
		if (stk_a->next)
		{
			vp->pa1 = (int)stk_a->next->content;
			if (stk_a->next->next)
			{
				while (stk_a->next->next)
					stk_a = stk_a->next;
				vp->pazm1 = stk_a->content;
				vp->paz = stk_a->next->content;
			}
		}
	}
}

void	init_vip(t_vip *vp, t_list *stk_a, t_list *stk_b)
{
	init_vip_a(vp, stk_a);
	init_vip_b(vp, stk_b);
}

int	find_p_match(int *arr_i, t_vip vp, t_list **stk_a, t_list **stk_b)
{
	if (vp.pa0 == arr_i[pb0 - 1]) // i.e. if belongs below pb0
	else if (vp.pa0 == arr_i[pb0 + 1]) // if belongs above pb0
	else if (vp.pa0 == arr_i[pbz - 1]) // if belongs below pbz
	else if (vp.pa0 == arr_i[pbz + 1]) // if belongs above pbz
}

void	pb_conds(int *arr_i, t_vip vp, t_list **stk_a, t_list **stk_b)
{
	if (!(*stk_b))
		op_psh(stk_a, stk_b);
	if (!find_p_match(arr_i, vp, stk_a, stk_b))
		fit_in();
}

int	sifting_ok(int *arr_ind, /*int size,*/ t_list **stk_a, t_list **stk_b)
{
	t_vip	vp;
	while (*stk_a)
	{
		init_vip(&vp, *stk_a, *stk_b);
		pb_conds(arr_i, vp, stk_a, stk_b);
	}
	return (0);
}
