/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputctrl_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 16:44:27 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	buffover_str(const char *nptr)
{
	long long	l;
	int			minus;

	l = 0;
	minus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			minus = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		l += *nptr - 48;
		l *= 10;
		nptr++;
	}
	l = l / 10 * minus;
	if (l > INT_MAX || l < INT_MIN)
		return (1);
	return (0);
}

void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	buff;
	int	swap;

	if (!arr)
		return ;
	swap = 1;
	while (swap == 1)
	{
		i = -1;
		swap = 0;
		while (++i < (size - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
				swap = 1;
			}
		}
	}
}

int	*index_arr(int *arr_raw, int size)
{
	int	i;
	int	*arr_ind;

	i = -1;
	arr_ind = (int *)malloc(sizeof(int) * size);
	if (!arr_ind)
	{
		free (arr_raw);
		return (NULL);
	}
	while (++i < size)
		arr_ind[i] = arr_raw[i];
	ft_bubble_sort(arr_ind, size);
	return (arr_ind);
}

int	dupes_present(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (size - 1))
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}
