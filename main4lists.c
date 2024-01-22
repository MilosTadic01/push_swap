#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	del(void *content)
{
	if (content)
		free(content);
	return ;
}

int	main(void)
{
	t_list	*head; // <-- conventional name for the first item of the list; must be a ptr
	t_list	*current;
	t_list	*prev;

	int i = 2;
	int j = 1;
	int k = 3;
	head = ft_lstnew(&i); // <-- [obsolete notes]
	ft_lstadd_front(&head, ft_lstnew(&j));
	ft_lstadd_back(&head, ft_lstnew(&k));
	printf("List length: %d\n", ft_lstsize(head));
	current = head;
	while (current != NULL)
	{
		printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	current = head; // reset it (general reset) to be able to iterate again
	// next step unrelated to the general reset in the prev step.
	prev = current;	// 1st step when about to del and bypass
	current = current->next; // set it to the node to delete (the one containing 2)
	ft_lstbypass(&prev, current->next); // bypass around the node to delete
	ft_lstdelone(&current, del); // free the mem alloc'd to the node
	current = head;
	printf("the node with the pointer to the number 2 was deleted and bypassed over\n");
		while (current != NULL)
	{
		printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	return (0);
}

/*





typedef struct		s_list
{
	void	*content;
	struct s_list	*next;
}			t_list;




*/
