#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		if (lst->next == NULL)
			return (lst);
		else
			while (lst->next)
				lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc (sizeof(t_stack));
	if (node)
	{
		node->value = content;
		node->next = NULL;
	}	
	return (node);
}
void	ft_lstadd_back(t_stack **lst, t_stack *ne)
{
	t_stack	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = ne;
		else
		{
			last = ft_lstlast(*lst);
			last->next = ne;
		}
	}
}
int add_to_list(t_stack **data ,char **bunch)
{
	int x;

	x = -1;
	while (bunch[++x])
		ft_lstadd_back(data, ft_lstnew(ft_atoi(bunch[x], data, bunch)));
	return (0);
}
int	create_list_all(t_stack **data, char **av)
{
	char	**store;
	int		x;

	x = 1;
	while (av[x])
	{
		store = ft_split(av[x], ' ');
		add_to_list(data, store);
		free_func(store);
		x++;
	}
	return(0);
}