/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:11 by yonamog2         ###   ########.fr       */
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

int check_duplicate(t_list **stack_a)
{
	t_list *tmp;
	t_list *tmp2;
	int x;
	int y;
	int dup;

	x = 0;
	tmp = (*stack_a); 
	while (tmp->next)
	{
		y = 0;
		dup = tmp->content;
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
	int x;

	x = 1;
	while (av[x])
	{
		if (check_validity(av[x]) == 1)
			exit_prog(head);
		x++;
	}
	return(0);
}

int check_sort(t_list **stack_a)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = (*stack_a);
	while (tmp->next)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->content > tmp1->content)
				return(1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;	
	}
	return(0);
}
void set_chunk_number(t_list **head)
{
	t_list *tmp;

	tmp = (*head);
	while (tmp->next)
	{
		tmp->chunk_num = 0;
		tmp = tmp->next;	
	}	
}
int validate_chunk(t_list **head)
{
	t_list *tmp;

	tmp = (*head);
	while (tmp->next)
	{
		if (tmp->chunk_num == 0)
			return(1);
		tmp = tmp->next;	
	}	
	return(0);
}

void set_index(t_list **head)
{
	int x;
	int count;
	t_list *tmp;
	t_list *tmp1;

	x = 0;
	tmp = (*head);
	while (tmp)
	{
		tmp->index = x;
		tmp = tmp->next;
		x++;
	}
	tmp = (*head);
	while (tmp)
	{
		tmp1 = (*head);
		count = 1;
		while (tmp1)
		{
			if (tmp1->content < tmp->content)
				count++;
			tmp1 = tmp1->next;
		}
		tmp->chunk_num = count;
		tmp = tmp->next;
	}
}

void sort_list(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int x = 5;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (x >= 0)
	{
		if (tmp_a->chunk_num % 2 == 0)
		{
			tmp_a->chunk_num /= 2;
			// pb(tmp_b, tmp_a);
			ra(tmp_a);
		}
		else if(tmp_a->chunk_num % 2 == 1)
		{
			tmp_a->chunk_num /= 2;
			pb(tmp_b, tmp_a);
		}
		x-- ;
		
	}
	
}
int	main(int ac, char **av)
{
	int		x;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tm;
	// t_list	*tm2;
	// char	**store;

	stack_a = 0;
	stack_b = 0;
	full_scan(av, &stack_a);
	if (ac == 1)
	{
		exit(1);
		// exit_prog(&stack_a);
	}
	else
	{
		create_list_all(&stack_a, av);
		x = check_duplicate(&stack_a);
		if (x == 1)
		{
			if (stack_a)
				exit_prog(&stack_a);
		}
		if (check_sort(&stack_a) == 0)
			exit(0);
		set_index(&stack_a);
		// int y = 10;
		// ft_printf("%d\n", y >> 1);
		// do_op(&stack_a, &stack_b);
		// ss(&stack_a, &stack_b);
		// tm2 = stack_b;
		//simple print debug
		tm = stack_a;
		while (tm)
		{
			ft_printf("stack_a[%d](%d): %d\n",tm->index , tm->chunk_num, tm->content);
			tm = tm->next;
		}
		// tm2 = stack_b;
		// ft_printf("\n\n");
		// while (tm2)
		// {
		// 	ft_printf("stack_b: %d\n",tm2->content);
		// 	tm2 = tm2->next;
		// }
	}
	if (stack_a)
		free_list(&stack_a);
	if (stack_b)
		free_list(&stack_b);
	return (0);
}
