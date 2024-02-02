/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:40 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 14:40:26 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <limits.h>

// checker.c
int	is_validinstr(char *instr);
char	*getinstr(int size);
t_list	*init_stk(int *arr, int size);

// sorting.c
int	go_do_op(t_list **stk_a, t_list **stk_b, char *instr);
int	go_sorting(int *arr_raw, char *instrset, int size);
int		isunsorted(t_list *stk, int end);

// inputctrl_pt1.c
int		input_str_valid(int argc, char **argv);
int		get_size_shell(int argc, char **argv);
void	get_size_core(int i, int *j, int *size, char **argv);
int		*handle_input(int argc, char **argv, int size);
int		handle_input_str(int h, int *indx, char **argv, int *arr_raw);

// inputctrl_pt2.c
int		dupes_present(int *arr, int size);
int		buffover_str(const char *nptr);

// liberators.c
char	*error_free_ptr(char *str1, char *str2);
int		error_message(int errno);
int		clearstk(t_list **stk_a, t_list **stk_b, int retval);
void	*free_arrays(int *arr_raw, int *arr_ind);

// operands.c
int		op_psh(t_list **stk_src, t_list **stk_dst);
int		op_rot(t_list **stk);
int		op_swp(t_list **stk);
int		op_revrot(t_list **stk);

#endif
