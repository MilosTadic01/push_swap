/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:55:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 17:50:14 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	op_psh(t_list **stk_src, t_list **stk_dst)
{
	t_list	*new_src_head;
	t_list	*new_dst_head;

	if (*stk_src == NULL)
		return (0);
	new_src_head = (*stk_src)->next;
	new_dst_head = *stk_src;
	new_dst_head->next = *stk_dst;
	*stk_dst = new_dst_head;
	*stk_src = new_src_head;
	return (1);
}

int	op_rot(t_list **stk)
{
	t_list	*newhead;
	t_list	*oldlast;

	if (!(*stk) || !((*stk)->next))
		return (0);
	newhead = (*stk)->next;
	oldlast = ft_lstlast(*stk);
	oldlast->next = *stk;
	oldlast->next->next = NULL;
	*stk = newhead;
	return (1);
}

int	op_swp(t_list **stk)
{
	t_list	*headcpy;
	t_list	*newhead;

	if (!(*stk) || !((*stk)->next))
		return (0);
	headcpy = *stk;
	newhead = (*stk)->next;
	headcpy->next = (*stk)->next->next;
	newhead->next = headcpy;
	*stk = newhead;
	return (1);
}

int	op_revrot(t_list **stk)
{
	t_list	*newhead;
	t_list	*snd2last;

	if (!(*stk) || !((*stk)->next) || !((*stk)->next->next))
		return (0);
	newhead = *stk;
	while (newhead->next->next != NULL)
		newhead = newhead->next;
	snd2last = newhead;
	newhead = newhead->next;
	newhead->next = *stk;
	snd2last->next = NULL;
	*stk = newhead;
	return (1);
}
