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

int	op_psh(char c, t_list **stk_src, t_list **stk_dst)
{
	t_list	*new_src_head;
	t_list	*new_dst_head;

	if (*stk_src == NULL || (*stk_src)->next == NULL)
		return (0);
	new_src_head = (*stk_src)->next;// val: src[1]
	new_dst_head = *stk_src;	// val: src[0]
	new_dst_head->next = *stk_dst;	// link 'nxt' of 'tobepushed' to the old dst head.
	*stk_dst = new_dst_head;	// deref dst to set the variable outside
	*stk_src = new_src_head;	// deref src to set the variable outside
	return (1);
}

int	op_rot(char c, t_list **stk)
{
	t_list	*headcpy;
	t_list	*lastcpy;

	if (!(*stk) || !((*stk)->next))
		return (0);
	headcpy = *stk;
	lastcpy = ft_lstlast(*stk);
	lastcpy->next = headcpy;
	lastcpy->next->next = NULL;
	*stk = (*stk)->next;
	lastcpy->next->next = NULL;
}

int	op_swp(char c, t_list **stk)
{
	t_list	*headcpy;
	t_list	*nextcpy;

	if (!(*stk) || !((*stk)->next) || !((*stk)->next->next))
		return (0);
	headcpy = *stk;
	nextcpy = (*stk)->next;
	headcpy->next = (*stk)->next->next;	// link 'nxt' of future lst[1] to lst[2]
	nextcpy->next = headcpy;		// link 'nxt' of future lst[0] to future lst[1]
	*stk = nextcpy;				// deref to set the variable outside
	return (1);
}

int	op_revrot(char c, t_list **stk)
{
	da;
}
