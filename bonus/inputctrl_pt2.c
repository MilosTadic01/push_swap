/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputctrl_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 12:51:54 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
