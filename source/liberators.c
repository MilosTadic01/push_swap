/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 16:01:35 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_arrays(int *arr_raw, int *arr_ind)
{
	if (arr_raw)
	{
		free (arr_raw);
		arr_raw = NULL;
	}
	if (arr_ind)
	{
		free (arr_ind);
		arr_ind = NULL;
	}
	return (NULL);
}

int	clearstk(t_list **stk_a, t_list **stk_b, int retval)
{
	ft_lstclear(stk_a);
	ft_lstclear(stk_b);
	return (retval);
}

int	error_message(int errno)
{
	write(2, "Error\n", 6);
	return (errno);
}
