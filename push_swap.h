/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:40 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/22 15:48:10 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include "./libft/libft.h"

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

#endif
