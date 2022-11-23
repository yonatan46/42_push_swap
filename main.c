/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/23 07:16:55 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_list(t_list **store)
{
	t_list	*tmp;

   while (*store)
    {
       tmp = *store;
       *store = (*store)->next;
       free(tmp);
    }
}
void	free_func(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}

int check_duplicate(t_list **head)
{
	t_list *tmp;
	t_list *tmp2;
	int x;
	int y;
	int dup;

	x = 0;
	tmp = (*head); 
	while (tmp->next)
	{
		y = 0;
		dup = tmp->content;
		// ft_printf("dup: %d\n", dup);
		tmp2 = (*head);
		while (tmp2)
		{
			if (y == x)
			{
				tmp2 = tmp2->next;
				y++;
			}
			// ft_printf("dup: %d\n", dup);
			// ft_printf("tmp :%d\n", tmp2->content);
			if (tmp2->content == dup)
				return(1);
			tmp2 = tmp2->next;
			y++;					
		}
		tmp = tmp->next;
		x++;
	}
	return (0);
}
int add_to_list(t_list **data ,char **bunch)
{
	int x;

	x = -1;
	while (bunch[++x])
		ft_lstadd_back(data, ft_lstnew(ft_atoi(bunch[x])));
	return (0);
}

int	create_list_all(t_list **data, char **av)
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
		return(1);
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

int	full_scan(char **av)
{
	int x;

	x = 1;
	while (av[x])
	{
		if (check_validity(av[x]) == 1)
			exit_prog();
		x++;
	}
	return(0);
}
// void	create_list(t_list **node, int ac, char **av)
// {
// 	int		y;

// 	y = 0;
// 	while (++y < ac)
// 	{
// 		// int res = ft_atoi(av[y]);
// 		ft_lstadd_back(node, ft_lstnew(ft_atoi(av[y])));
// 	}
// }

// void do_operation(t_list **head)
// {
	
// }

int	main(int ac, char **av)
{
	int		x;
	t_list	*head;
	t_list	*tm;
	// char	**store;

	head = 0;
	full_scan(av);
	if (ac == 1)
		exit_prog();
	else
	{
		create_list_all(&head, av);
		x = check_duplicate(&head);
		if (x == 1)
		{
			free_list(&head);
			exit_prog();
		}
		tm = head;
		while (tm)
		{
			ft_printf("content: %d\n",tm->content);
			tm = tm->next;
		}
	}
	if (head)
		free_list(&head);
	return (0);
}
