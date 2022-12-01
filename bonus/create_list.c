/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:15:46 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 18:14:00 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (node)
	{
		node->value = content;
		node->next = 0;
	}	
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *ne)
{
	t_list	*last;

	if (lst)
	{
		if (*lst == 0)
			*lst = ne;
		else
		{
			last = get_stack_bottom(*lst);
			last->next = ne;
		}
	}
}

int	add_to_list(t_list **data, char **bunch)
{
	int	x;

	x = -1;
	while (bunch[++x])
		ft_lstadd_back(data, ft_lstnew(ft_atoi(bunch[x], data, bunch)));
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
	return (0);
}
