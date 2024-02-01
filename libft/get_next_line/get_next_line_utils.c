/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:26 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/01 17:29:42 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_chrwhere(char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

void	free_if_extant(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free (*s1);
		(*s1) = NULL;
	}
	if (s2 && *s2)
	{
		free (*s2);
		(*s2) = NULL;
	}
	return ;
}
