/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:03:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:15:53 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortsmall(t_list **stk_a)
{
	if (*stk_a && (*stk_a)->next)
		op_swp(stk_a, 'a');
}

int	isunsorted(t_list *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (*(int *)stk->content >= *(int *)stk->next->content)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	isrevunsorted(t_list *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (*(int *)stk->content <= *(int *)stk->next->content)
			return (1);
		stk = stk->next;
	}
	return (0);
}

void	prt_stcks(t_list *a, t_list *b, int midval)
{
	if (!a && !b)
		return ;
	ft_printf("Midval was: %i", midval);
	ft_printf("\nContents stack B: ");
	while (b)
	{
		ft_printf("%i ", *(int *)b->content);
		b = b->next;
	}
	ft_printf("\nContents stack A: ");
	while (a)
	{
		ft_printf("%i ", *(int *)a->content);
		a = a->next;
	}
	ft_printf("\n");
}
