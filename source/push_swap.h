/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:40 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/12 15:32:38 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

// main.c
t_list	*init_stk(int *arr, int size);

// inputctrl_pt1.c
int		input_str_valid(int argc, char **argv);
int		get_size_shell(int argc, char **argv);
void	get_size_core(int i, int *j, int *size, char **argv);
int		*handle_input(int argc, char **argv, int size);
int		handle_input_str(int h, int *indx, char **argv, int *arr_raw);

// inputctrl_pt2.c
int		dupes_present(int *arr, int size);
int		*index_arr(int *arr_raw, int size);
void	ft_bubble_sort(int *arr, int size);
int		buffover_str(const char *nptr);

// midpoint_sorting.c
int		go_midpointing(int *arr_raw, int *arr_ind, int size);
void	pb_all_check(int *arr_ind, int size, t_list **stk_a, t_list **stk_b);
void	pb_all_engine(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b);

// sort_upto3.c
void	sort_upto3(int *arr_ind, int size, t_list **stk_a, t_list **stk_b);
void	upto3_ifpos0(t_list **stk_a, t_list **stk_b);
void	upto3_ifpos1(int nxt, t_list **stk_a);
void	upto3_ifpos2(int nxt, t_list **stk_a);

// flip_b.c
void	flip_b(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b);
void	flip_b_base(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b);
void	pa_abovemid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b);

// flip_a.c
void	flip_a(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b);
void	pb_belowmid(int *arr_ind, int howmny, t_list **stk_a, t_list **stk_b);

// flip_utils.c
int		isunsorted(t_list *stk, int chunksz);
int		isrevunsorted(t_list *stk, int chunksz);
void	prt_stcks(t_list *a, t_list *b, int midval);
void	ft_sortsmall(t_list **stk_a);

// operands.c
int		op_psh(t_list **stk_src, t_list **stk_dst, char dest_stk_name);
int		op_rot(t_list **stk, char stk_name);
int		op_swp(t_list **stk, char stk_name);
int		op_revrot(t_list **stk, char stk_name);

// liberators.c
int		error_message(int errno);
int		clearstk(t_list **stk_a, t_list **stk_b, int retval);
void	*free_arrays(int *arr_raw, int *arr_ind);

#endif
