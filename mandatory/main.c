/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:20 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 18:01:22 by yonamog2         ###   ########.fr       */
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

void	check_dup_and_exit(t_var *vars)
{
	vars->x = check_duplicate(&vars->stack_a);
	if (vars->x == 1)
	{
		if (vars->stack_a)
			exit_prog(&vars->stack_a);
	}
}

int	main(int ac, char **av)
{
	t_var	vars;

	if (ac < 2)
		return (0);
	full_scan(av, &vars.stack_a);
	vars.stack_b = NULL;
	vars.stack_a = NULL;
	create_list_all(&vars.stack_a, av);
	check_dup_and_exit(&vars);
	if (check_sort(vars.stack_a) == 1)
	{
		free_list(&vars.stack_a);
		return (0);
	}
	set_chunk_num(&vars.stack_a);
	push_swap(&vars.stack_a, &vars.stack_b);
	if (vars.stack_a)
		free_list(&vars.stack_a);
	if (vars.stack_b)
		free_list(&vars.stack_b);
	return (0);
}
