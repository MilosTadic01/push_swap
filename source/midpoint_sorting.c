#include "push_swap.h"

int	ischunk_revunsrtd(int midval, int chunksz, t_list *stk_b)
{
	int	i;
	t_list	*tocmp;

	i = 0;
	tocmp = NULL;
	while (stk_b != NULL && i < chunksz) // just being extra by checking stk_b
	{
		if (*(int *)stk_b->content >= midval)
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

void	prt_stcks(t_list *a, t_list *b, int midval)
{
	if (!a && !b)
		return ;
	ft_printf("Midval was: %i", midval);
	ft_printf("\nContents stack B: ");
	while (b)
	{
		ft_printf("%i ", *(int *)b->content);
		b = b->next;
	}
	ft_printf("\nContents stack A: ");
	while (a)
	{
		ft_printf("%i ", *(int *)a->content);
		a = a->next;
	}
	ft_printf("\n");
}

void	ft_pa_filter(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b)
{
	int	i;

	i = -1;
	while(++i < mid)
	{
		if ((*(int *)(*stk_b)->content) > arr_ind[mid])
		{
			op_psh(stk_b, stk_a);
			ft_printf("pa\n");
		}
		else
		{
			while ((*(int *)(*stk_b)->content) <= arr_ind[mid])
			{
				op_rot(stk_b);
				ft_printf("rb\n");
			}
			op_psh(stk_b, stk_a);
			ft_printf("pa\n");
		}
	}
}

void	flip_b(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.4
{
	int	mid;
	int	i;
	int	rotcount;

	mid = chunksz / 2;
	i = -1;
	rotcount = 0;
	if (mid == 0)
	{
		ft_printf("\nWe're in mid == 0\n");
		op_psh(stk_b, stk_a);
		ft_printf("pa\n");
		prt_stcks(*stk_a, *stk_b, *(int *)(*stk_a)->content);
		return (1);
	}
	else if (chunksz == 2)
	{
		ft_printf("\nWe're in chunksz == 2\n");
		while (++i < 2)
		{
			while (*(int *)(*stk_b)->content < arr_ind[0])
			{
				rotcount++;
				op_rot(stk_b);
				ft_printf("rb\n");
			}
			if ((*(int *)(*stk_b)->content >= arr_ind[0]))
			{
				op_psh(stk_b, stk_a);
				ft_printf("pa\n");
				prt_stcks(*stk_a, *stk_b, arr_ind[0]);
			}
		}
		while (rotcount-- > 0)
		{
			op_revrot(stk_b);
			ft_printf("rrb\n");
		}
		if (isunsorted(*stk_a, 2))
		{
			op_swp(stk_a);
			ft_printf("sa\n");
		}
		return (2);
	}
	else
	{
		flip_b(&arr_ind[mid], mid, stk_a, stk_b);
		ft_pa_filter(arr_ind, mid, stk_a, stk_b);
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
			op_psh(stk_a, stk_b);
			ft_printf("pb\n");
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

	mid = ft_lstsize(*stk_a) / 2; // and not size, right?
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
		flip_b(arr_ind, mid, stk_a, stk_b);		// v.4 bouncy recursive
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
	while (stk_a) //
	{
		ft_printf("Content stk_a: %i\n", *(int *)stk_a->content); //
		stk_a = stk_a->next; //
	} //
	while (stk_b) //
	{
		ft_printf("Content stk_b: %i\n", *(int *)stk_b->content); //
		stk_b = stk_b->next; //
	} //
	return (clearstk(&stk_a, &stk_b, 1));
}
