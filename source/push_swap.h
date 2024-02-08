/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:40 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/06 15:15:02 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct values
{
	int	size;
	int	smol;
	int	next;
	int	step;
}	t_vl;

typedef struct op_numbers
{
	int	pos_last;
	int	pos_smol;
	int	pos_next;
}	t_op;

// main
void	push_swap(int argc, char **argv);
t_list	*init_stk(int *arr, int size);

// midpoint_sorting.c
int	go_midpointing(int *arr_raw, int *arr_ind, int size);
void	midpoint_sort(int *arr_ind, int size, t_list **stk_a, t_list **stk_b);
void	ft_sortsmall(t_list **stk_a);
void	ft_pb_filter(int *arr_ind, int mid, t_list **stk_a, t_list **stk_b);
int	midpoint_pa(int *arr_ind, int chunksz, t_list **stk_a, t_list **stk_b); // recursive v.2
void	prt_stcks(t_list *a, t_list *b);
int	ischunk_revunsrtd(int midval, int chunksz, t_list *stk_b);

// sorting.c
int		go_sorting(int *arr_raw, int *arr_ind, int size);
void	find_n_swap(int *arr_ind, t_vl *vl, t_list **stk_a, t_list **stk_b);
int		isunsorted(t_list *stk, int end);

int		input_str_valid(int argc, char **argv);
int		get_size_shell(int argc, char **argv);
void	get_size_core(int i, int *j, int *size, char **argv);
int		*handle_input(int argc, char **argv, int size);
int		handle_input_str(int h, int *indx, char **argv, int *arr_raw);

int		dupes_present(int *arr, int size);
int		*index_arr(int *arr_raw, int size);
void	ft_bubble_sort(int *arr, int size);
int		buffover_str(const char *nptr);

int		error_message(int errno);
int		clearstk(t_list **stk_a, t_list **stk_b, int retval);
void	*free_arrays(int *arr_raw, int *arr_ind);

int		conds_if_a(t_op *op, t_vl *vl, t_list **stk_a, t_list **stk_b);
void	c_a_exp(t_op *op, t_vl *vl, t_list **stk_a, t_list **stk_b);
int		conds_if_b(t_op *op, t_vl *vl, t_list **stk_a, t_list **stk_b);
void	conds_a_weigh(t_op *op, t_vl *vl, t_list **stk_a, t_list **stkb);
void	conds_b_weigh(t_op *op, t_list **stk_a, t_list **stk_b);

void	conds_steps_a_a(t_list **stk_a);
void	conds_steps_a_b(t_list **stk_a);
void	conds_steps_a_c(t_list **stk_a);
void	conds_steps_a_d(t_list **stk_a);
void	conds_steps_a_e(t_list **stk_a, t_list **stk_b);

void	conds_steps_a_f(t_list **stk_a);
void	conds_steps_a_g(t_list **stk_a);
void	conds_steps_a_h(t_list **stk_a, t_list **stk_b);

void	conds_steps_b_a(t_list **stk_a, t_list **stk_b);
void	conds_steps_b_b(t_list **stk_a, t_list **stk_b);
void	conds_steps_b_c(t_list **stk_a, t_list **stk_b);
void	conds_steps_b_d(t_list **stk_a, t_list **stk_b);
void	conds_steps_b_e(t_list **stk_a, t_list **stk_b);

void	conds_steps_b_f(t_list **stk_b);
void	conds_steps_b_g(t_list **stk_b);

int		op_psh(t_list **stk_src, t_list **stk_dst);
int		op_rot(t_list **stk);
int		op_swp(t_list **stk);
int		op_revrot(t_list **stk);

#endif
