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

void	prt_stcks(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	ft_printf("Contents stack A: ");
	while (a)
	{
		ft_printf("%i ", *(int *)a->content);
		a = a->next;
	}
	ft_printf("\nContents stack B: ");
	while (b)
	{
		ft_printf("%i ", *(int *)b->content);
		b = b->next;
	}
	ft_printf("\n");
}

// (chunksz - mid - 1) == how many to push
int	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.3
{
	int	mid;
	int	i;
	int	rotcount;
	int	sent;

	mid = chunksz / 2;
	i = -1;
	rotcount = 0;
	sent = 0;
	if (mid == 0)
	{
		op_psh(stk_b, stk_a);
		ft_printf("pa\n");
		prt_stcks(*stk_a, *stk_b);
		return (1);
	}
	else if (chunksz == 2)
	{
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
				prt_stcks(*stk_a, *stk_b);
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
	else if ((chunksz - mid - 1) < 3 && mid < ft_lstsize(*stk_b)) 
	{
		while (++i < (chunksz - mid - 1))
		{
			while (*(int *)(*stk_b)->content <= arr_ind[mid])
			{
				rotcount++;
				op_rot(stk_b);
				ft_printf("rb\n");
			}
			op_psh(stk_b, stk_a);
			ft_printf("pa\n");
			prt_stcks(*stk_a, *stk_b);
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
		return (i);
	}
	else
	{
		sent = midpoint_pa(&arr_ind[mid], mid, stk_a, stk_b);
		while (mid - sent > 0)
			sent += midpoint_pa(&arr_ind[mid], (mid - sent), stk_a, stk_b);
		return (sent);
		// if we have two left...
		// I'm still convinced we have to call midpoint_pa a second time, probably
		// best in the form of 'if' statement, though it might also be always necessary.
		// So if 5, 6 were pa'd, then midpoint could return 2, we substract that from
		// chunk size (6), and we know we have 4 elements left. We relay the 4 as info
		// to the second call, but...how? The only option is as chunksz. And then...
		// Ok, I see. So same arr_ind instead of &arr_ind[mid]?
		// But new chunksz. But I already tried that...where did I go wrong?
	}
}
/*
void	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.2
{
	int	i;
	int	mid;
	int	rotcount;

	i = -1;
	rotcount = 0;
	mid = chunksz / 2;
	if (!ischunk_revunsrtd(arr_ind[mid], chunksz, *stk_b)) // base case 1, you can loop outside of recursion too
	{
		while (++i < mid)
		{
			if ((*(int *)(*stk_b)->content) < arr_ind[mid])
			{
				op_psh(stk_b, stk_a);
				ft_printf("pa\n");
			}
			else
			{
				while (*(int *)(*stk_b)->content >= arr_ind[mid])
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
	else if (mid < 3) // base case 2 (for 7, 8 from video)
	{
		while (++i < mid)
		{
			while ((*(int *)(*stk_b)->content) >= arr_ind[mid])
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
		midpoint_pa(arr_ind, mid, stk_a, stk_b);
	}
}
*/

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
	int	sent;

	mid = ft_lstsize(*stk_a) / 2;
	sent = size; // temp solution for 'size unused' warning, delete later?
	sent = 0;
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
		// midpoint_pa(arr_ind, mid, stk_a, stk_b); // for v.2 recursive
		sent = midpoint_pa(arr_ind, mid, stk_a, stk_b); // v.3 recursive
		while (mid - sent > 0)
			sent += midpoint_pa(arr_ind, (mid - sent), stk_a, stk_b);
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
	// sent = midpoint_pa(arr_ind, (size / 4), &stk_a, &stk_b);
	// if ((size / 4) - sent > 0)
	// 	midpoint_pa(arr_ind, ((size / 4) - sent), &stk_a, &stk_b);
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
