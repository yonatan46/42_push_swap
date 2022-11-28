#include "push_swap.h"
// int check_sort(t_stack **stack_a)
// {
// 	t_stack *tmp;
// 	t_stack *tmp1;

// 	tmp = (*stack_a);
// 	while (tmp->next)
// 	{
// 		tmp1 = tmp->next;
// 		while (tmp1)
// 		{
// 			if (tmp->value > tmp1->value)
// 				return(1);
// 			tmp1 = tmp1->next;
// 		}
// 		tmp = tmp->next;	
// 	}
// 	return(0);
// }
int check_duplicate(t_stack **stack_a)
{
	t_stack *tmp;
	t_stack *tmp2;
	int x;
	int y;
	int dup;

	x = 0;
	tmp = (*stack_a); 
	while (tmp->next)
	{
		y = 0;
		dup = tmp->value;
		// ft_printf("dup: %d\n", dup);
		tmp2 = (*stack_a);
		while (tmp2)
		{
			if (y == x)
			{
				tmp2 = tmp2->next;
				y++;
			}
			// ft_printf("dup: %d\n", dup);
			// ft_printf("tmp :%d\n", tmp2->value);
			if (tmp2->value == dup)
				return(1);
			tmp2 = tmp2->next;
			y++;					
		}
		tmp = tmp->next;
		x++;
	}
	return (0);
}
int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

int	scan_str(char *av)
{
	int	x;

	x = 0;
	if ((av[x] == '-' || av[x] == '+') && av[x + 1])
		x++;
	while (av[x])
	{
		if (!(ft_isdigit(av[x])))
			return (1);
		x++;
	}
	return (0);
}
int	check_validity(char *av)
{
	char	**store;
	int		x;

	x = 0;
	if (av[0] == '\0')
		return (1);
	store = ft_split(av, ' ');
	if (store[0] == NULL)
	{
		free(store);
		return (1);
	}
	while (store[x])
	{
		if (scan_str(store[x]) == 1)
		{
			free_func(store);
			return (1);
		}
		x++;
	}
	if (store)
		free_func(store);
	return (0);
}
int	full_scan(char **av, t_stack **head)
{
	int x;

	(void)head;
	x = 1;
	while (av[x])
	{
		if (check_validity(av[x]) == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
			// exit_prog(head);
		}
		x++;
	}
	return(0);
}