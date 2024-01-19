/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:49:02 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/19 19:30:27 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		del((void *)(*lst)->content);
		free(*lst);
		*lst = NULL;
	}
	return ;
}
