/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/21 23:21:23 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (av[0] == '\0' || av[0] == ' ')
		return (1);
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
	// int		x;
	// t_list	*head;
	// char	**store;

	// head = NULL;
	check = full_scan(av);
	if (ac == 1 || check == 1)
		write(2, "Error\n", 6);
	else
	{
		// store = ft_split(av[1], ' ');
		// x = -1;
		// while (store[++x])
		// {
		// 	ft_printf("split: %s\n",store[x]);
		// }
		
		write(1, "finew\n", 6);
	}
	return (0);
}
