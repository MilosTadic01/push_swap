/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sifting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:20:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/03 18:29:32 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	solvable_wo_b(int *arr_r, int *arr_i, int size)
{
	int	i;

	i = 0;
	while (i < (size - 2))
	{
		if ((arr_r[i] < arr_r[i + 1] || arr_r[i] < arr_r[i + 2]) || \
			arr_r[i] == arr_i[size - 1] || \
			(arr_r[i] == arr_i[size - 2] && i > 0 && \
			arr_r[i - 1] == arr_i[size - 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	sifting_ok(int *arr_ind, int size, t_list **stk_a, t_list **stk_b)
{
	t_vip	vip;
	while ((*stk_b) != NULL && isunsorted(stk_a, size))
	{
		init_vip(&vip, *stk_a, *stk_b);
		while (ft_lstsize((*stk_b) < size / 2)) // dok nisu jednake velicine
		{
			if (*stk_a
		}
	}
	else
	{
		;
		return (1);
	}
	return (0)
}
