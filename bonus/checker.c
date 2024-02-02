/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/01 14:11:43 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char	*getinstr(int size)
{
	int	i;
	char	*instr;
	char	*instrset;
	int	alsz;

	instr = NULL;
	alsz = size * 50;
	instrset = (char *)ft_calloc(alsz * sizeof(char));
	if (!instrset)
		return (error_free_ptr(instr, instrset));
	i = 0;
	while (1)
	{
		instr = get_next_line(0);
		if (!instr) // if EOF : ctrl+d
			return (instrset);
		if (ft_strlen(instr) > 4 || \			// if non-valid single instr
				ft_strlcat(instrlst, instr, alsz) > alsz) // if too many instr
			return (error_free_ptr(instr, instrset));
		free (instr);
		instr = NULL;
	}
}


int	main(int argc, char **argv)
{
	int	size;
	int	*arr_raw;
	int	*arr_ind;
	char	*instrset;

	if (argc == 1)
		return (1);
	if (!input_str_valid(argc, argv))
		return (error_message(1));
	size = get_size_shell(argc, argv);
	
	instrset = getinstr(size);
	if (!instrset)
		return (error_message(2));

	arr_raw = handle_input(argc, argv, size);
	if (!arr_raw)
		return (error_message(2));
	arr_ind = index_arr(arr_raw, size); // prolly don't need arr_ind
	if (!arr_ind)
		return (2);
	if (!go_sorting(arr_raw, arr_ind, size)) // take your instrset and godspeed, strncmp
	{
		arr_raw = free_arrays(arr_raw, arr_ind);
		return (3);
	}
	free_arrays(arr_raw, arr_ind);
	free(instrset);				// gotta do this in the end
	return (0);
}
