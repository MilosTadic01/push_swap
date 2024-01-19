#include "libft.h"

void	ft_lstbypass(t_list **last, t_list *next)
{
	(*last)->next = next;
	return ;
}
