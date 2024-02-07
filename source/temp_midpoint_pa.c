int	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b) // recursive v.3
{
	int	mid;
	int	i;
	int	rotcount;

	mid = chunksz / 2;
	i = -1;
	rotcount = 0;
	if (mid < 3)
	{
		while (++i < mid)
		{
			if (*(int *)stk_b->content < arr_ind[mid])
			{
				op_psh(stk_b, stk_a);
				ft_printf("pa\n");
			}
			else
			{
				while (*(int *)stk_b->content >= arr_ind[mid])
				{
					rotcount++;
					op_rot(stk_b);
					ft_printf("rb\n");
				}
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
	}
	else
	{
		midpoint_pa(&arr_ind[mid], mid, stk_a, stk_b);
		midpoint_pa(arr_ind, mid, stk_a, stk_b);
	}
}
