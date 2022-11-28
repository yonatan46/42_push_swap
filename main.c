/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:20 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/28 18:00:45 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *stack)
{
	while (stack->next != 0)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2 && !check_sort(*stack_a))
		do_sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && !check_sort(*stack_a))
		sort(stack_a, stack_b);
}

void	set_index(t_list **head)
{
	int		x;
	t_list	*tmp;

	x = 1;
	tmp = (*head);
	while (tmp)
	{
		tmp->index = x;
		tmp = tmp->next;
		x++;
	}
}

void	set_chunk_num(t_list **head)
{
	int		count;
	t_list	*tmp;
	t_list	*tmp1;

	tmp = (*head);
	while (tmp)
	{
		tmp1 = (*head);
		count = 1;
		while (tmp1)
		{
			if (tmp1->value < tmp->value)
				count++;
			tmp1 = tmp1->next;
		}
		tmp->index = count;
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		x;

	if (ac < 2)
		return (0);
	full_scan(av, &stack_a);
	stack_b = NULL;
	stack_a = NULL;
	create_list_all(&stack_a, av);
	x = check_duplicate(&stack_a);
	if (x == 1)
	{
		if (stack_a)
			exit_prog(&stack_a);
	}
	if (check_sort(stack_a) == 1)
	{
		free_list(&stack_a);
		return (0);
	}
	set_chunk_num(&stack_a);
	push_swap(&stack_a, &stack_b);
	if (stack_a)
		free_list(&stack_a);
	if (stack_b)
		free_list(&stack_b);
	return (0);
}
