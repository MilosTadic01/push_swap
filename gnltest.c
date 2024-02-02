/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:50:01 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 15:59:32 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./source/push_swap.h"

int	main(void)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		ft_printf("%s", str);
		if (!str)
			return (0);
		free(str);
		str = NULL;
	}
	return (0);
}
