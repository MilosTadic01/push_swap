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

int	op_psh(t_list **stk_src, t_list **stk_dst)
{
	t_list	*new_src_head;
	t_list	*new_dst_head;

	if (*stk_src == NULL)
		return (0);
	new_src_head = (*stk_src)->next;// val: src[1]
	new_dst_head = *stk_src;	// val: src[0]
	new_dst_head->next = *stk_dst;	// link 'nxt' of 'tobepushed' to the old dst head.
	*stk_dst = new_dst_head;	// deref dst to set the variable outside
	*stk_src = new_src_head;	// deref src to set the variable outside
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
	oldlast->next->next = NULL;	// should be the same as '*stk->next = NULL;'
	*stk = newhead;
	return (1);
}

int	op_swp(t_list **stk)
{
	t_list	*headcpy;
	t_list	*newhead;

	if (!(*stk) || !((*stk)->next) || !((*stk)->next->next))
		return (0);
	headcpy = *stk;
	newhead = (*stk)->next;
	headcpy->next = (*stk)->next->next;	// link 'nxt' of future lst[1] to lst[2]
	newhead->next = headcpy;		// link 'nxt' of future lst[0] to future lst[1]
	*stk = newhead;				// deref to set the variable outside
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
	snd2last = newhead;			// get 2nd to last
	newhead = newhead->next;		// get last;
	newhead->next = *stk;			// link new head (old last) to old head;
	snd2last->next = NULL;			// link 2nd to last to NULL;
	*stk = newhead;
	return (1);
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*current;
	int	*arr;
	int	i = -1;
	int	size = 5;

	arr = (int *)malloc(size * sizeof(int));
	while (++i < size)
		arr[i] = i;
	i = -1;
	while (++i < size)
		ft_lstadd_back(&head, ft_lstnew(&arr[i]));
	current = head;
	ft_printf("No operations performed\n");
	while (current != NULL)
	{
		ft_printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	op_swp(&head);
	current = head;
	ft_printf("op_swp performed\n");
	while (current != NULL)
	{
		ft_printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	op_rot(&head);
	current = head;
	ft_printf("op_rot performed\n");
	while (current != NULL)
	{
		ft_printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	op_revrot(&head);
	current = head;
	ft_printf("op_revrot performed\n");
	while (current != NULL)
	{
		ft_printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	return (0);
}
*/
