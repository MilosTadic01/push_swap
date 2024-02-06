#include "push_swap.h"

void	ft_pa_chunk(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // loop v.1
{
	int	i;
	int	mid;
	int	rotcount;
	int	j;

	i = -1;
	mid = chunksz / 2;
	rotcount = 0;
	j = -1;
	while (++i < chunksz)
	{
		if (isunsorted(*stk_b, chunksz))
			keeptrack_rb(stk_b, chunksz);
		while (*(int *)(*stk_b)->content !> arr_ind[mid])
		{
			op_rot(stk_b);
			rotcount++;
		}
		while (++j < rotcount)
			op_psh(stk_b, stk_a);
	}
	j = -1;
	while (++j < rotcount)
		op_revrot(stk_b);
}

void	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.2
{
	int	i;
	int	mid;
	int	rotcount;

	i = -1;
	mid = chunksz / 2;
	if (!isrevunsorted(*stk_b, chunksz))	// base case 1, you can loop outside of recursion too
	{
		while (++i < chunksz)
			op_psh(stk_b, stk_a);
	}
	else if (chunksz == 2) // base case 2 (for 7, 8 from video)
	{
		while (chunksz-- > 0)
		{
			while (*(int *)(*stk_b)->content !> arr_ind[mid])
			{
				rotcount++;
				op_rot(stk_b);
			}
			op_psh(stk_b, stk_a);
		}
		if (*(int *)(*stk_a)->content > *(int *)(*stk_a)->next-content)
			op_swp(stk_a);
		while (++i < rotcount)
			op_revrot(stk_b);
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
		if (*(int *)(*stk_a)->content < arr_ind[mid])
			op_psh(stk_a, stk_b);
		else if (*(int *)ft_lstlast(*stk_a)->content < arr_ind[mid])
		{
			op_revrot(stk_a);
			op_psh(stk_a, stk_b);
		}
		else
		{
			while (*(int *)(*stk_a)->content !< arr_ind[mid])
				op_rot(stk_a);
		}
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
		ft_pa_chunk(arr_ind, mid, stk_a, stk_b); // for v.1 loop
							 // for v.2 recursive
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
	midpoint_sort(arr_ind, size, &stk_a, &stk_b)
	return (clearstk(&stk_a, &stk_b, 1));
}
