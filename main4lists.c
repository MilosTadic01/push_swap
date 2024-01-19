#include "libft.h"
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
	int	*ptri = malloc(sizeof(int));
	int	*ptrj = malloc(sizeof(int));
	int	*ptrk = malloc(sizeof(int));

	*ptri = 2;
	*ptrj = 1;
	*ptrk = 3;
	head = ft_lstnew((void *)ptri); // <-- note that we malloc for t_list, we just assgn the address to a
				      // ptr to t_list; so a t_list itself does exist!
	ft_lstadd_front(&head, ft_lstnew((void *)ptrj));
	ft_lstadd_back(&head, ft_lstnew((void *)ptrk));
	printf("List length: %d\n", ft_lstsize(head));
	current = head;
	while (current != NULL)
	{
		printf("Current content: %i\n", *(int *)current->content);
		current = current->next;
	}
	current = head; // reset it
	current = current->next; // set it to the node containing 2
	ft_lstdelone(current, del); // free the mem alloc'd to the content and to the node itself
	current = head;
	printf("*ptri was deleted, and so was the 2 it was pointing to\n");
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
