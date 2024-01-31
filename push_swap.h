/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:40 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/31 14:49:38 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>

void	push_swap(int argc, char **argv);

typedef struct	values
{
	int	size;
	int	smol;
	int	next;
}	vl_data;

typedef struct	op_numbers
{
	int	pos_last;
	int	pos_smol;
	int	pos_next;
}	op_data;

int	op_psh(t_list **stk_src, t_list **stk_dst);
int	op_rot(t_list **stk);
int	op_swp(t_list **stk);
int	op_revrot(t_list **stk);

#endif
