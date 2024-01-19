/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:48:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/15 18:49:01 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mpd_head;
	t_list	*mpd_new;

	if (!lst || !f || !del)
		return (NULL);
	mpd_head = (NULL);
	while (lst)
	{
		mpd_new = ft_lstnew(f((void *)lst->content));
		if (!mpd_new)
		{
			ft_lstclear(&mpd_head, del);
			return (NULL);
		}
		ft_lstadd_back(&mpd_head, mpd_new);
		lst = lst->next;
	}
	return (mpd_head);
}
