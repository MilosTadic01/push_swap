/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/29 17:01:35 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	del(void *content)
{
	if (content)
		free(content);
	return ;
}

int	isunsorted(t_list *sta, int end)
{
	int	i;

	i = -1;
	while (sta && sta->next && ++i < end)
	{
		if (*(int *)sta->content >= *(int *)sta->next->content)
			return (1);
		sta = sta->next;
	}
	return (0);	// if NULL passed or *stk->next == NULL, (0) is the desired outcome
}

int	buffover(const char *nptr)
{
	long long	l;
	int		minus;
	
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

t_list	*init_stk(int *arr, int size)
{
	int	i;
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
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
	}
	return (head);
}

int	conds_if_b(op_data *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
	{
		op_psh(stk_b, stk_a);
		op_rot(stk_a);
		ft_printf("pa\nra\n");
	}
	else if (op->pos_smol == 1)
	{
		if (op->pos_next == 0)
		{
			op_swp(stk_b);
			op_psh(stk_b, stk_a);
			op_rot(stk_a);
			ft_printf("sb\npa\nra\n");
		}
		else if (op->pos_next == 2)
		{
			op_rot(stk_b);
			op_psh(stk_b, stk_a);
			op_rot(stk_a);
			ft_printf("rb\npa\nra\n");
		}
		else
		{
			op_rot(stk_b);
			op_psh(stk_b, stk_a);
			op_rot(stk_a);
			ft_printf("rb\npa\nra\n");
		}
	}
	else if (op->pos_smol == op->pos_last)
	{
		op_revrot(stk_b);
		op_psh(stk_b, stk_a);
		op_rot(stk_a);
		ft_printf("rrb\npa\nra\n");
	}
	else if (op->pos_smol == (op->pos_last - 1)) // note: may happen always
	{
		op_revrot(stk_b);
		op_revrot(stk_b);
		op_psh(stk_b, stk_a);
		op_rot(stk_a);
		ft_printf("rrb\nrrb\npa\nra\n");
	}
	else
	{
		++(*step);
		return (0);
	}
	return (++(*step));
}

void	conds_b_weigh(op_data *op, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	if (op->pos_smol > op->pos_last / 2)
	{
		while (++i <= (op->pos_last - op->pos_smol)) // key difference: '='
		{
			op_revrot(stk_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while (++i < op->pos_smol)
		{
			op_rot(stk_b);
			ft_printf("rb\n");
		}
	}
	op_psh(stk_b, stk_a);
	op_rot(stk_a);
	ft_printf("pa\nra\n");
}

void	conds_a_weigh(op_data *op, int *step, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	if (*step == 0 && op->pos_smol > op->pos_last / 2)
	{
		while (++i < (op->pos_last - op->pos_smol))
		{
			op_revrot(stk_a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (++i < op->pos_smol)
		{
			op_psh(stk_a, stk_b);
			ft_printf("pb\n");
		}
		op_rot(stk_a);
		ft_printf("ra\n");
	}
}

int	conds_if_a(op_data *op, int *step, t_list **stk_a, t_list **stk_b)
{
	if (op->pos_smol == 0)
	{
		if (op->pos_next == op->pos_last && !isunsorted((*stk_a)->next, op->pos_last - 1 - 1))
		{
			op_revrot(stk_a);
			op_swp(stk_a);
			ft_printf("rra\nsa\n");
		}
		else
		{
			op_rot(stk_a);
			ft_printf("ra\n");
		}
	}
	else if (op->pos_smol == 1)
	{
		if (op->pos_next == 0)
		{
			if (*step == 0 && !(*stk_b) && !isunsorted((*stk_a)->next->next, INT_MAX))
			{
				op_swp(stk_a);
				ft_printf("sa\n");
			}
			else
			{
				op_swp(stk_a);
				op_rot(stk_a);
				ft_printf("sa\nra\n");
			}
		}
		else if (!(*stk_b) && !isunsorted((*stk_a)->next, INT_MAX))
		{
			op_rot(stk_a);
			ft_printf("ra\n");
		}
		else
		{
			op_psh(stk_a, stk_b);
			op_rot(stk_a);
			ft_printf("pb\nra\n");
		}
	}
	else if (*step == 0 && op->pos_next == (op->pos_last - 1) && \
			op->pos_smol == (op->pos_last) && !isunsorted(*stk_a, op->pos_last - 2))
	{
		op_revrot(stk_a);
		op_revrot(stk_a);
		op_swp(stk_a);
		ft_printf("rra\nrra\nsa\n");
	}
	else if (op->pos_smol == op->pos_last)
		;
	else if (*step == 0 && op->pos_smol == (op->pos_last - 1)) // note: may only happen if 0th step
	{
		op_revrot(stk_a);
		ft_printf("rra\n");
	}
	// else if (*step == 0 && op->pos_smol > op->pos_last / 2) <-- implied smol is in a.
	//	loop until op_revrot(stk_a);
	else
	{
		++(*step);
		return (0);
	}
	return (++(*step));
}

void	find_n_swap(int *arr_ind, vl_data *vl, t_list **stk_a, t_list **stk_b)
{
	static int	step = 0;
	op_data	op;

	op.pos_smol = ft_lstintpos(*stk_a, arr_ind[vl->smol]);
	if (op.pos_smol == -1)
		op.pos_smol = ft_lstintpos(*stk_b, arr_ind[vl->smol]);
	op.pos_next = ft_lstintpos(*stk_a, arr_ind[vl->next]);
	if (op.pos_next == -1)
		op.pos_next = ft_lstintpos(*stk_b, arr_ind[vl->next]);
	// op.pos_last = vl->size - 1; <--obsoleted inside conditions below
	if (ft_lstintpos(*stk_a, arr_ind[vl->smol]) != -1)
	{
		op.pos_last = ft_lstsize(*stk_a) - 1;
		if (!conds_if_a(&op, &step, stk_a, stk_b))
			conds_a_weigh(&op, &step, stk_a, stk_b);
	}
	else
	{
		op.pos_last = ft_lstsize(*stk_b) - 1;
		if (!conds_if_b(&op, &step, stk_a, stk_b))
			conds_b_weigh(&op, stk_a, stk_b);
	}
}

int	go_sorting(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;
	vl_data	vl;

	stk_a = init_stk(arr_raw, size);
	if (!stk_a || !isunsorted(stk_a, size))
		return (0);
	stk_b = NULL;
	vl.size = size;
	vl.smol = -1;
	while (++vl.smol < size)
	{
		vl.next = vl.smol; // <-- just more space-efficient for me to write 'else' this way
		if (vl.smol < (size - 1))
			vl.next = (vl.smol + 1);
		find_n_swap(arr_ind, &vl, &stk_a, &stk_b);
		if (!stk_b && !isunsorted(stk_a, INT_MAX))
			break;
	}
	while (stk_a) //
	{
		ft_printf("Content: %i\n", *(int *)stk_a->content); //
		stk_a = stk_a->next; //
	} //
	ft_lstclear(&stk_a, del);
	ft_lstclear(&stk_b, del); //
	return (1);
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
	// int	buff;
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

int	handle_input_brain(int *i, int *j, char **argv, int *arr_raw)
{
	char	c;

	c = argv[1][*i];
	if (ft_iswhite(c))
		++(*i);
	else
	{
		if (buffover(&argv[1][*i]))
			return (0);
		arr_raw[*j] = ft_atoi(&argv[1][*i]); // <-- doch, '&argv'
		while (c != 0 && (ft_isdigit(c) || ft_isplusminus(c)))
			c = argv[1][++(*i)];
		++(*j);
	}
	return (1);
}

int	*handle_input(char **argv, int size)
{
	int	i;
	int	j;
	int	*arr_raw;

	i = 0;
	j = 0;
	arr_raw = (int *)malloc(size * sizeof(int));
	if (!arr_raw)
		return (NULL);
	while (argv[1][i])
	{
		if (handle_input_brain(&i, &j, argv, arr_raw) == 0)
			return(free_arrays(arr_raw, NULL));
	}
	if (dupes_present(arr_raw, size))
		return (free_arrays(arr_raw, NULL));
	return (arr_raw);
}


int	get_size(char **argv)
{
	int	i;
	int	size;
	char	c;

	i = 0;
	size = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (ft_iswhite(c))
			i++;
		else
		{
			while (c != 0 && (ft_isdigit(c) || c == 43 || c == 45))
				c = argv[1][++i];
			size++;
		}
	}
	return (size);
}

int	input_str_valid(char **argv)
{
	int		i;
	char	c;

	i = -1;
	while (argv[1][++i])
	{
		c = argv[1][i];
		if (!(ft_isdigit(c) || ft_iswhite(c) || c == 43 || c == 45))
			return (0);
		if ((c == 43 || c == 45) && !(ft_isdigit(argv[1][i + 1])))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*arr_raw;
	int	*arr_ind;

	if (argc == 1) // specified in the pdf as "do nothing if no parameters"
		return (1);
	if (argc != 2 || !input_str_valid(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	size = get_size(argv);
	arr_raw = handle_input(argv, size);
	if (!arr_raw)
	{
		ft_printf("Error\n");
		return (2);
	}
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


// So Homework: give members of int * to linked-list contents, then see what
// happens when you change the values.


// ultimately how to check the next smallest
// i++;
// smallest = arr_ind[i];
// that's it bby; that's why we make that presorted arr_ind
