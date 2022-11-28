/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:13:48 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/28 17:38:49 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list **stack_a)
{
	t_var	vars;
	t_list	*tmp;
	t_list	*tmp2;

	vars.x = 0;
	tmp = (*stack_a);
	while (tmp->next)
	{
		vars.y = 0;
		vars.z = tmp->value;
		tmp2 = (*stack_a);
		while (tmp2)
		{
			if (vars.y == vars.x)
			{
				tmp2 = tmp2->next;
				vars.y++;
			}
			if (tmp2->value == vars.z)
				return (1);
			tmp2 = tmp2->next;
			vars.y++;
		}
		tmp = tmp->next;
		vars.x++;
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
	if (store[0] == 0)
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

int	full_scan(char **av, t_list **head)
{
	int	x;

	(void)head;
	x = 1;
	while (av[x])
	{
		if (check_validity(av[x]) == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		x++;
	}
	return (0);
}
