/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputctrl_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 16:43:26 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_input_str(int h, int *indx, char **argv, int *arr_raw)
{
	int	i;

	i = 0;
	while (argv[h][i])
	{
		if (ft_iswhite(argv[h][i]))
			++i;
		else
		{
			if (buffover_str(&argv[h][i]))
				return (0);
			arr_raw[*indx] = ft_atoi(&argv[h][i]);
			if (ft_isintmacro(&argv[h][i]))
				i = i + 7;
			while (argv[h][i] != 0 && (ft_isdigit(argv[h][i]) || \
					ft_isplusminus(argv[h][i])))
				++i;
			++(*indx);
		}
	}
	return (1);
}

int	*handle_input(int argc, char **argv, int size)
{
	int	h;
	int	*arr_raw;
	int	indx;

	h = 0;
	indx = 0;
	arr_raw = (int *)malloc(size * sizeof(int));
	if (!arr_raw)
		return (NULL);
	while (++h < argc)
	{
		if (handle_input_str(h, &indx, argv, arr_raw) == 0)
			return (free_arrays(arr_raw, NULL));
	}
	if (dupes_present(arr_raw, size))
		return (free_arrays(arr_raw, NULL));
	return (arr_raw);
}

void	get_size_core(int i, int *j, int *size, char **argv)
{
	while (argv[i][*j] != 0 && ft_iswhite(argv[i][*j]))
		++(*j);
	if (argv[i][*j] == 0)
		return ;
	if (ft_isintmacro(&argv[i][*j]))
	{
		*j = *j + 7;
		++(*size);
	}
	else
	{
		while (argv[i][*j] != 0 && (ft_isdigit(argv[i][*j]) || \
					ft_isplusminus(argv[i][*j])))
			++(*j);
		++(*size);
	}
}

int	get_size_shell(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
			get_size_core(i, &j, &size, argv);
	}
	return (size);
}

int	input_str_valid(int argc, char **argv)
{
	int		h;
	int		i;

	h = 0;
	while (++h < argc)
	{
		i = 0;
		while (argv[h][i])
		{
			while (argv[h][i] != 0 && ft_iswhite(argv[h][i]))
				++i;
			if (ft_isintmacro(&argv[h][i]))
				i = i + 7;
			if (argv[h][i] != 0 && !(ft_isdigit(argv[h][i]) || \
			ft_iswhite(argv[h][i]) || ft_isplusminus(argv[h][i])))
				return (0);
			if (argv[h][i] != 0 && ft_isplusminus(argv[h][i]) && \
				!(ft_isdigit(argv[h][i + 1])))
				return (0);
			if (argv[h][i] != 0)
				i++;
		}
	}
	return (1);
}
