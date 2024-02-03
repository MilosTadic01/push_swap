/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 18:14:32 by mitadic          ###   ########.fr       */
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

int	is_validinstr(char *instr)
{
	if (ft_strncmp(instr, "sa\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "sb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "ss\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "ra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "rb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "rr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "pa\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "pb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(instr, "rra\n", 5) == 0)
		return (1);
	else if (ft_strncmp(instr, "rrb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(instr, "rrr\n", 5) == 0)
		return (1);
	else
		return (0);
}

char	*getinstr(int size)
{
	char	*instr;
	char	*instrset;
	size_t	alsz;

	instr = NULL;
	alsz = size * 50;
	instrset = (char *)ft_calloc(alsz, sizeof(char));
	if (!instrset)
		return (error_free_ptr(instr, instrset));
	while (1)
	{
		instr = get_next_line(0);
		if (!instr)
			return (instrset);
		if (!is_validinstr(instr) || \
				ft_strlcat(instrset, instr, alsz) > alsz)
			return (error_free_ptr(instr, instrset));
		free (instr);
		instr = NULL;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	int		*arr_raw;
	char	*instrset;

	if (argc == 1)
		return (1);
	if (!input_str_valid(argc, argv))
		return (error_message(1));
	size = get_size_shell(argc, argv);
	arr_raw = handle_input(argc, argv, size);
	if (!arr_raw)
		return (error_message(2));
	instrset = getinstr(size);
	if (!instrset)
		return (error_message(2));
	if (!go_sorting(arr_raw, instrset, size)) 
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_arrays(arr_raw, NULL);
	free(instrset);
	return (0);
}
