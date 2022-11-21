/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/21 23:00:52 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int check_double(int ac, char **av)
// {
// 	int x;
// 	int y;

// 	x = 1;
// 	while (x < ac)
// 	{
// 		y = 1;
// 		while (y < ac)
// 		{
// 			if (x == y)
// 				y++;
// 			if(ft_strncmp(av[x], av[y], ft_strlen(av[x])) == 0)
// 				return(1);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return(0);
// }
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
int	scan_backwards(char *av)
{
	int y;

	y = ft_strlen(av);
	// y--;
	//sacn from the back
	while (av[y])
	{
		while (av[y] == ' ' || av[y] == '\n' || av[y] == '\t'
			|| av[y] == '\v' || av[y] == '\r' || av[y] == '\f')
			y--;
		if (ft_isdigit(av[y]) != 1)
			return (1);
		y--;
	}
	return (0);
}

int	scan_str(char *av)
{
	int x;

	x = 0;
	if ((av[x] == '-' || av[x] == '+') && av[x + 1])
		x++;
	while (av[x])
	{
		if (!(ft_isdigit(av[x])))
			return(1);
		x++;
	}
	
	return (0);
}

int	check_validity(char *av)
{
	char	**store;
	int		x;

	x = 0;
	store = ft_split(av, ' ');
	while (store[x])
	{
		if (scan_str(store[x]) == 1)
		{
			free_func(store);
			return (1);
		}
		x++;
	}
	free_func(store);
	return (0);
}

int full_scan(char **av)
{
	int x;

	x = 1;
	while (av[x])
	{
		if (check_validity(av[x]) == 1)
			return(1);
		x++;
	}
	return(0);
}
void	create_list(t_list **node, int ac, char **av)
{
	int		y;

	y = 0;
	while (++y < ac)
		ft_lstadd_back(node, ft_lstnew(ft_atoi(av[y])));
}

int	main(int ac, char **av)
{
	int		check;
	// t_list	*head;
	// char	**store;

	// head = NULL;
	check = full_scan(av);
	if (ac != 1 && check == 0)
	{
		
	}
	
	if (ac == 1 || check == 1)
		write(2, "Error\n", 6);
	else
	{
		write(1, "finew\n", 6);
		// while (store[++x])
		// 	ft_printf("%s\n", store[x]);
		// if(check_validity(ac, av) == 1)
		// {
		// 	write(2, "Error\n", 6);
		// 	return (0);
		// }
		// create_list(&head, ac, av);
		// while (head)
		// {
		// 	ft_printf("content: %d\n",head->content);
		// 	head = head->next;
		// }
	}
	return (0);
}
