/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:55:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/26 18:18:34 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_psh(char c, t_list **stk_src, t_list **stk_end)
{
	t_list	*headcpy;

	ft_lstadd_front(stk_end, ft_lstnew(stk_src->content));
	headcpy = *stk_src;
	*stk_src = (*stk_src->next);
	ft_lstdelone(headcpy, del);
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return ;
}

void	op_rot(char c, t_list **stk)
{
	da;
}

void	op_swp(char c, t_list **stk)
{
	da;
}

void	op_revrot(char c, t_list **stk)
{
	da;
}
