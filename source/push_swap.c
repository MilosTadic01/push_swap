/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 16:45:32 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stk(int *arr, int size)
{
	int		i;
	t_list	*head;
	t_list	*new;

	i = -1;
	head = NULL;
	while (++i < size)
	{
		new = NULL;
		new = ft_lstnew(&(arr[i]));
		if (!new)
		{
			ft_lstclear(&head);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
	}
	return (head);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*arr_raw;
	int	*arr_ind;

	if (argc == 1)
		return (1);
	if (!input_str_valid(argc, argv))
		return (error_message(1));
	size = get_size_shell(argc, argv);
	arr_raw = handle_input(argc, argv, size);
	if (!arr_raw)
		return (error_message(2));
	arr_ind = index_arr(arr_raw, size);
	if (!arr_ind)
		return (2);
	if (!go_sorting(arr_raw, arr_ind, size))
	{
		arr_raw = free_arrays(arr_raw, arr_ind);
		return (3);
	}
	free_arrays(arr_raw, arr_ind);
	return (0);
}
