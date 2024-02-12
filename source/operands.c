/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:55:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 14:54:15 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_psh(t_list **stk_src, t_list **stk_dst, char dest_stk_name)
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
	if (dest_stk_name == 'b')
		ft_printf("pb\n");
	else if (dest_stk_name == 'a')
		ft_printf("pa\n");
	return (1);
}

int	op_rot(t_list **stk, char stk_name)
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
	if (stk_name == 'b')
		ft_printf("rb\n");
	else if (stk_name == 'a')
		ft_printf("ra\n");
	return (1);
}

int	op_swp(t_list **stk, char stk_name)
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
	if (stk_name == 'b')
		ft_printf("sb\n");
	else if (stk_name == 'a')
		ft_printf("sa\n");
	return (1);
}

int	op_revrot(t_list **stk, char stk_name)
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
	if (stk_name == 'b')
		ft_printf("rrb\n");
	else if (stk_name == 'a')
		ft_printf("rra\n");
	return (1);
}
