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

	int	*arr;
	int	i = -1;
	int	size = 5;

	arr = (int *)malloc(size * sizeof(int));
	while (++i < size)
		arr[i] = i;
	head = ft_lstnew(&arr[1]); // <-- [obsolete notes]
	ft_lstadd_front(&head, ft_lstnew(&arr[0]));
	ft_lstadd_back(&head, ft_lstnew(&arr[2]));
	i = 2;
	while (++i < size)
		ft_lstadd_back(&head, ft_lstnew(&arr[i]));
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
	printf("the node with the pointer to arr[1] was deleted and bypassed over\n");
	printf("List length: %d\n", ft_lstsize(head));
	while (current != NULL)
	{
		printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	printf("Where is val '1' in the LL? ft_lstintpos says: %i\n", ft_lstintpos(head, 1));
	printf("Where is val '2' in the LL? ft_lstintpos says: %i\n", ft_lstintpos(head, 2));
	printf("Where is val '4' in the LL? ft_lstintpos says: %i\n", ft_lstintpos(head, 4));
	i = -1;
	printf("We're at the end now, free everything\n");
	free (arr);
	ft_lstclear(&head, del);
	return (0);
}

/*





typedef struct		s_list
{
	void	*content;
	struct s_list	*next;
}			t_list;




*/
