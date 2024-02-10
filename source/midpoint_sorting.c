#include "push_swap.h"

void	ft_sortsmall(t_list **stk_a)
{
	if (*stk_a && (*stk_a)->next)
	{
		op_swp(stk_a);
		ft_printf("sa\n");
	}
}

int	isunsorted(t_list *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (*(int *)stk->content >= *(int *)stk->next->content)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	isrevunsrtd(t_list *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (*(int *)stk->content <= *(int *)stk->next->content)
			return (1);
		stk = stk->next;
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

void	pb_belowmid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b)
{
	ft_printf("\n++Enter pb_belowmid++, arr_ind[0] == %i and howmny == %i++\n", arr_ind[0], howmny);
	prt_stcks(*stk_a, *stk_b, arr_ind[0]);
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while (*(int *)(*stk_a)->content >= arr_ind[0])
		{
			rotcount++;
			op_rot(stk_a);
			ft_printf("ra\n");
			if (rotcount > 10)
			{
				ft_printf("Error in pb_belowmid: cuz all >= than %i\n", arr_ind[0]);
				prt_stcks(*stk_a, *stk_b, arr_ind[0]);
				break ;
			}
		}
		if ((*(int *)(*stk_a)->content < arr_ind[0]))
		{
			op_psh(stk_a, stk_b);
			ft_printf("pb\n");
			// prt_stcks(*stk_a, *stk_b, arr_ind[0]);
		}
	}
	while (rotcount-- > 0)
	{
		op_revrot(stk_a);
		ft_printf("rra\n");
	}
}

void	flip_a(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.4
{
	ft_printf("\n++Enter flip_a, arr_ind[0] == %i and chunksz == %i++\n", arr_ind[0], chunksz);
	prt_stcks(*stk_a, *stk_b, arr_ind[0]);
	int	mid;
	int	restsz;

	mid = chunksz / 2;
	if (chunksz % 2 == 0)
		restsz = chunksz - mid + 1;
	else
		restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		ft_printf("We're in A and chunksz <= 2\n");
		if (isunsorted(*stk_a, 2))
		{
			op_swp(stk_a);
			ft_printf("sa\n");
		}
		return ;
	}
	pb_belowmid(&arr_ind[mid], mid, stk_a, stk_b);
	flip_b(arr_ind, restsz, stk_a, stk_b);
	ft_printf("\n****gonna enter flip_a from flip_a****");
	flip_a(&arr_ind[mid], restsz, stk_a, stk_b);
	// pa_abovemid(&arr_ind[mid], chunksz - mid - 1, stk_a, stk_b);
	// flip_a(&arr_ind[mid + 1], chunksz - mid - 1, stk_a, stk_b);
	// flip_b(arr_ind, restsz, stk_a, stk_b);
}

void	pa_abovemid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b)
{
	ft_printf("\n++Enter pa_abovemid++, arr_ind[0] == %i and howmny == %i++\n", arr_ind[0], howmny);
	prt_stcks(*stk_a, *stk_b, arr_ind[0]);
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while (*(int *)(*stk_b)->content <= arr_ind[0])
		{
			rotcount++;
			op_rot(stk_b);
			ft_printf("rb\n");
			if (rotcount > 10)
			{
				ft_printf("Error in pa_abovemid: cuz all <= %i\n", arr_ind[0]);
				ft_printf("Error in pa_abovemid: howmny == %i\n", howmny);
				break ;
			}
			prt_stcks(*stk_a, *stk_b, arr_ind[0]);
		}
		if ((*(int *)(*stk_b)->content > arr_ind[0]))
		{
			op_psh(stk_b, stk_a);
			ft_printf("pa\n");
			// prt_stcks(*stk_a, *stk_b, arr_ind[0]);
		}
	}
	while (rotcount-- > 0)
	{
		op_revrot(stk_b);
		ft_printf("rrb\n");
	}
}

void	flip_b(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.4
{
	ft_printf("\n++Enter flip_b++, arr_ind[0] == %i and chunksz == %i++\n", arr_ind[0], chunksz);
	prt_stcks(*stk_a, *stk_b, arr_ind[0]);
	int	mid;
	int	i;
	int	rotcount;
	int	restsz;

	mid = chunksz / 2;
	if (chunksz % 2 == 0)
		restsz = chunksz - mid + 1;
	else
		restsz = chunksz - mid;
	i = -1;
	rotcount = 0;
	// if (chunksz == 1) //		| sends 10;
	// {
	// 	ft_printf("We're in B and chunksz == 1\n");
	// 	op_psh(stk_b, stk_a);
	// 	ft_printf("pa\n");
	// 	prt_stcks(*stk_a, *stk_b, *(int *)(*stk_a)->content);
	// 	return ;
	// }
	if (chunksz <= 2)
	{
		ft_printf("We're in B and chunksz <= 2\n");
		while (++i < chunksz)
		{
			while (*(int *)(*stk_b)->content < arr_ind[0])
			{
				rotcount++;
				op_rot(stk_b);
				ft_printf("rb\n");
				if (rotcount >  10)
				{
					ft_printf("Error in flip_b: cuz all less than %i\n", arr_ind[0]);
					prt_stcks(*stk_a, *stk_b, arr_ind[0]);
					break ;
				}
			}
			if ((*(int *)(*stk_b)->content >= arr_ind[0])) // handles both '10' and pairs
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
		return ;
	}
	//					// chunksz is 6		| chunksz is 3
	pa_abovemid(&arr_ind[mid], chunksz - mid - 1, stk_a, stk_b); // sends 5, 6	| sends 9
	flip_a(&arr_ind[mid + 1], chunksz - mid - 1, stk_a, stk_b);  // sees to 5, 6;returns | sees that the 9 is ok
	ft_printf("\n****gonna enter flip_b recursively****");
	flip_b(arr_ind, restsz, stk_a, stk_b); // restsz is 4		| fetches 7, 8;
					       //			| 7, 8, 9, 10, 11, 12 is sorted;
					       //			| we step out of this flip_b, sz is 6
}


// The rcrsv srt ft. Just being extra for no real reason in the base case cond.
void	pb_all_check(int *arr_ind, int size, t_list **stk_a, t_list **stk_b)
{
	int	mid;
	int	rest;

	mid = size / 2;
	rest = size - mid;
	if (size <= 2)
	{
		if (isunsorted(*stk_a, 2))
			ft_sortsmall(stk_a); // (0, 1)
		return ;
	}
	pb_all_engine(arr_ind, mid, stk_a, stk_b); // look for & send nb less than arr[mid], mid times
	pb_all_check(&arr_ind[mid], rest, stk_a, stk_b); // for 1-11: &arr[1] == 10, rest == 2, returns;
	flip_b(arr_ind, mid, stk_a, stk_b); // v.4 bouncy recrsv	| on 1st call, mid == 1!!!!
					// 				| go back, mid is 3. Then 6. & done.
					// 				| changed flip_b call 2 &arr_ind[mid]
}

int	go_midpointing(int *arr_raw, int *arr_ind, int size)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_a = init_stk(arr_raw, size);
	stk_b = NULL;
	if (!stk_a || !isunsorted(stk_a, size))
		return (clearstk(&stk_a, &stk_b, 0));
	pb_all_check(arr_ind, size, &stk_a, &stk_b);
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

void	pb_all_engine(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b)
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
