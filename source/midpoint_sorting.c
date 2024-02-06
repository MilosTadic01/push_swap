#include "push_swap.h"

int	ischunk_revunsrtd(int mid, int chunksz, t_list *stk_b)
{
	int	i;
	t_list	*tocmp;

	i = 0;
	tocmp = NULL;
	while (stk_b != NULL && i < chunksz) // just being extra by checking stk_b
	{
		if (*(int *)stk_b->content <= mid)
			stk_b = stk_b->next;
		else
		{
			if (tocmp != NULL && (*(int *)tocmp->content <= *(int *)stk_b->content))
				return (1);
			tocmp = stk_b;
			i++;
		}
	}
	return (0);
}

void	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.2
{
	int	i;
	int	mid;
	int	rotcount;

	i = -1;
	mid = chunksz / 2;
	if (!ischunk_revunsrtd(mid, chunksz, *stk_b)) // base case 1, you can loop outside of recursion too
	{
		while (chunksz-- > 0)
		{
			if ((*(int *)(*stk_b)->content) > arr_ind[mid])
			{
				op_psh(stk_b, stk_a);
				ft_printf("pa\n");
			}
			else
			{
				while (*(int *)(*stk_b)->content <= arr_ind[mid])
				{
					rotcount++;
					op_rot(stk_b);
					ft_printf("rb\n");
				}
				op_psh(stk_b, stk_a);
				ft_printf("pa\n");
			}
		}
		while (rotcount-- > 0)
		{
			op_revrot(stk_b);
			ft_printf("rrb\n");
		}
	}
	else if (chunksz < 3) // base case 2 (for 7, 8 from video)
	{
		while (chunksz-- > 0)
		{
			while ((*(int *)(*stk_b)->content) <= arr_ind[mid])
			{
				rotcount++;
				op_rot(stk_b);
				ft_printf("rb\n");
			}
			op_psh(stk_b, stk_a);
			ft_printf("pa\n");
		}
		if ((*(int *)(*stk_a)->content) > (*(int *)(*stk_a)->next->content))
		{
			op_swp(stk_a);
			ft_printf("sa\n");
		}
		while (++i < rotcount)
		{
			op_revrot(stk_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		// if (*(int *)(*stk_b)->content > arr_ind[mid])// no, not here
		// ft_pa_filter?				// no, bc no good values to rrb
		midpoint_pa(&arr_ind[mid], mid, stk_a, stk_b);
	}
}

void	ft_pb_filter(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	while(++i < mid)
	{
		if ((*(int *)(*stk_a)->content) < arr_ind[mid])
		{
			op_psh(stk_a, stk_b);
			ft_printf("pb\n");
		}
		else if (*(int *)ft_lstlast(*stk_a)->content < arr_ind[mid])
		{
			op_revrot(stk_a);
			op_psh(stk_a, stk_b);
			ft_printf("rra\npb\n");
		}
		else
		{
			while ((*(int *)(*stk_a)->content) >= arr_ind[mid])
			{
				op_rot(stk_a);
				ft_printf("ra\n");
			}
		}
	}
}

void	ft_sortsmall(t_list **stk_a)
{
	if (*stk_a && (*stk_a)->next)
	{
		op_swp(stk_a);
		ft_printf("sa\n");
	}
}

// The rcrsv srt ft. Just being extra for no real reason in the base case cond.
void	midpoint_sort(int *arr_ind, int size, t_list **stk_a, t_list **stk_b)
{
	int	mid;

	mid = size / 2;
	if (((*stk_a) != NULL && (*stk_a)->next == NULL) || \
			(*stk_a)->next->next == NULL)
	{
		if (isunsorted(*stk_a, INT_MAX))
			ft_sortsmall(stk_a); // (0, 1)? or (0, 1, 2)?
		return ;
	}
	else
	{
		ft_pb_filter(arr_ind, mid, stk_a, stk_b);
		midpoint_sort(&arr_ind[mid], mid, stk_a, stk_b);
		// ft_pa_chunk(arr_ind, mid, stk_a, stk_b); // for v.1 loop
		midpoint_pa(&arr_ind[mid], mid, stk_a, stk_b); // for v.2 recursive
	}
}

int	go_midpointing(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = init_stk(arr_raw, size);
	stk_b = NULL;
	if (!stk_a || !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	midpoint_sort(arr_ind, size, &stk_a, &stk_b);
	return (clearstk(&stk_a, &stk_b, 1));
}
