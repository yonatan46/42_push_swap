/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/20 14:56:11 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_validity(char **av)
{
	int x;

	x = 0;
	while (av[++x])
	{
		if (ft_atoi(av[x]) == -1)
			return(1);
	}
	return(0);	
}
void create_list(t_list **node, int ac, char **av)
{
	int		y;

	y = 1;
	while (y < ac)
	{
		ft_lstadd_back(node, ft_lstnew((void *)av[y]));
		y++;
	}
}

int	main(int ac, char **av)
{
	int		x;
	t_list	*head;

	head = NULL;
	x = ac;
	if (ac == 1)
		ft_printf("Error!\n");
	else
	{
		if(check_validity(av) == 1)
		{
			ft_printf("Sorry only numbers!\n");
			return(0);
		}
		create_list(&head, ac, av);
		ra(&head);
		while (head)
		{
			ft_printf("%s\n",(char *)head->content);
			head = head->next;
		}
	}
	return (0);
}
