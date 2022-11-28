/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:03:42 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/27 23:06:08 by yonamog2         ###   ########.fr       */
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
	t_list *tmp;

	x = 1;
	tmp = (*head);
	while (tmp)
	{
		tmp->index = x;
		tmp = tmp->next;
		x++;
	}
}

void set_chunk_num(t_list **head)
{
	int count;
	t_list *tmp;
	t_list *tmp1;
	
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

int	find_highest_index(t_list *stack)
{
	int		index;

	index = stack->chunk_num;
	while (stack)
	{
		if (stack->chunk_num > index)
			index = stack->chunk_num;
		stack = stack->next;
	}
	return (index);
}

void sort_three(t_list **stack)
{
	int		highest;
	highest = find_highest_index(*stack);
	if ((*stack)->chunk_num == highest)
	{
		ft_printf("ra\n");
		ra(stack);
	}
	else if ((*stack)->next->chunk_num == highest)
	{
		ft_printf("rra\n");
		rra(stack);
	}
	if ((*stack)->chunk_num > (*stack)->next->chunk_num)
	{
		ft_printf("sa\n");
		sa(stack);
	}
}
void sort_list_second(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int x;
	int i;
	int size;
	int start;
	int end;

	start = 0;
	end  = 20;
	while (*stack_a && end <= 100)
	{
		tmp = (*stack_a);
		size = ft_lstsize(*stack_a);
		while (tmp)
		{
			if (tmp->chunk_num >= start && tmp->chunk_num <= end)
			{
				i = tmp->index;
				x = ft_lstsize(*stack_a);
				if (i <= x / 2)
				{
					while (--i)
					{
						ft_printf("ra\n");
						ra(stack_a);
					}
					ft_printf("pb\n");
					pb(stack_b, stack_a);
				}
				else
				{
					while (++i <= x + 2)
					{
						ft_printf("rra\n");
						rra(stack_a);
					}
					ft_printf("pb\n");
					pb(stack_b, stack_a);
				}
				if (end == 20 && size <= end - 10)
					set_index(stack_a);
				else if(tmp->chunk_num <= end - 10)
				{
					ft_printf("pb\n");
					rb(stack_b);
				}
				set_index(stack_a);
				tmp = (*stack_a);
			}
			else
				tmp = tmp->next;		
		}
		start += 20;
		end   += 20;
	}
	// ft_printf("----------finished: pushing to b------------\n");
	set_index(stack_b);
	while (start >= 1)
	{
		while (ft_lstsize(*stack_b) >= start)
		{
			tmp = (*stack_b);
			size = ft_lstsize(*stack_b);
			while (tmp != NULL && size != start - 1)
			{
				i = ft_lstsize(*stack_b);
				while (tmp->chunk_num != size)
					tmp = tmp->next;
				if (tmp->chunk_num == size)
				{
					x = tmp->index;
					if (x <= i / 2)
						while (--x)
						{
							ft_printf("rb\n");
							rb(stack_b);
						}
					else
						while (++x != i + 2)
						{
							ft_printf("rrb\n");
							rrb(stack_b);
						}
					ft_printf("pa\n");
					pa(stack_a, stack_b);
					size--;
					set_index(stack_b);
					tmp = *stack_b;
					// ft_printf("----------pushed: %d------------\n", (*stack_a)->content);
					// ft_printf("----------start: %d------------\n", start);
					// ft_printf("----------size: %d------------\n", size);
				}
			}
		}
		start = start - 20;
		// ft_printf("----------start at end: %d------------\n", start);
	}
	set_index(stack_b);
	if (start >= 0 && start < 20)
	{
		// ft_printf("----------finished: first pa------------\n");
		while (ft_lstsize(*stack_b) > 0)
		{
			tmp = (*stack_b);
			size = ft_lstsize(*stack_b);
			while (tmp != NULL && size != 0)
			{
				i = ft_lstsize(*stack_b);
				while (tmp->chunk_num != size)
					tmp = tmp->next;
				if (tmp->chunk_num == size)
				{
					x = tmp->index;
					if (x <= i / 2)
						while (--x)
						{
							ft_printf("rb\n");
							rb(stack_b);
						}
					else
						while (++x < i + 2)
						{
							ft_printf("rrb\n");
							rrb(stack_b);
						}
					ft_printf("pa\n");
					pa(stack_a, stack_b);
					size--;
					set_index(stack_b);
					tmp = (*stack_b);
				}
			}
		}
		// ft_printf("----------finished: last pa------------\n");
		set_index(stack_a);
		// ft_printf(" stack_a: %d\n", (*stack_a)->content);
	}
}

void sort_list(t_list **stack_a, t_list **stack_b)
{
	int		y;

	while (check_sort(stack_a))
	{
		y = ft_lstsize(*stack_a);
		while (y)
		{
			if ((*stack_a)->chunk_num % 2 == 1)
			{
				ft_printf("ra\n");
				(*stack_a)->chunk_num /= 2;
				ra(stack_a);
			}
			else if ((*stack_a)->chunk_num % 2 == 0)
			{
				ft_printf("pb\n");
				(*stack_a)->chunk_num /= 2;
				pb(stack_b, stack_a);
			}
			y--;
		}
		if ((*stack_b))
		{
			while ((*stack_b))
			{
				ft_printf("pa\n");
				pa(stack_a, stack_b);
			}
		}
	}
}

void		push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_printf("pb\n");
			pb(stack_b, stack_a);
			pushed++;
		}
		else
		{
			ft_printf("ra\n");
			ra(stack_a);
		}
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_printf("pb\n");
		pb(stack_b, stack_a);
		pushed++;
	}
}
static void	do_rev_rotate_both(t_list **a, t_list **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_printf("rrr\n");
		rrr(a, b);
	}
}
static void	do_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_printf("rr\n");
		rr(a, b);
	}
}
static void	do_rotate_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_printf("ra\n");
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_printf("rra\n");
			rra(a);
			(*cost)++;
		}
	}
}
static void	do_rotate_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_printf("rb\n");
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_printf("rrb\n");
			rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	ft_printf("pa\n");
	pa(a, b);
}
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

static int	get_target(t_list **a, int b_idx,
								int target_idx, int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}
static void	get_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target_position(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
int	get_lowest_index_position(t_list **stack)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_printf("rra\n");
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_printf("ra\n");
			ra(stack_a);
			lowest_pos--;
		}
	}
}
void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (check_sort(stack_a) == 1)
		shift_stack(stack_a);
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
		set_chunk_num(&stack_a);
		// if (ft_lstsize(stack_a) == 2)
		// {
		// 	ft_printf("sa\n");
		// 	sa(&stack_a);
		// }
		if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_list(&stack_a, &stack_b);
		// int y = 10;
		// ft_printf("%d\n", y >> 1);
		// do_op(&stack_a, &stack_b);
		// ss(&stack_a, &stack_b);
		// set_index(&stack_a);
		// tm2 = stack_b;
		// // //simple print debug
		// pb(&stack_b, &stack_a);
		// pa(&stack_a, &stack_b);
		// rb(&stack_b);
		tm = stack_a;
		while (tm)
		{
			ft_printf("stack_a[%d](%d): %d\n",tm->index , tm->chunk_num, tm->content);
			// ft_printf("%d\n",tm->content);
			tm = tm->next;
		}
		
		// tm2 = stack_b;
		// ft_printf("\n\n");
		// while (tm2)
		// {
		// 	ft_printf("stack_b[%d](%d): %d\n",tm2->index , tm2->chunk_num, tm2->content);
		// 	tm2 = tm2->next;
		// }
	}
	if (stack_a)
		free_list(&stack_a);
	if (stack_b)
		free_list(&stack_b);
	return (0);
}
