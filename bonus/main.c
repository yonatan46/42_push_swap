/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:16:20 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 23:37:20 by yonamog2         ###   ########.fr       */
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

void	check_dup_and_exit(t_var *vars)
{
	vars->x = check_duplicate(&vars->stack_a);
	if (vars->x == 1)
	{
		if (vars->stack_a)
			exit_prog(&vars->stack_a);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s2[x])
	{
		if ((s1[x] > s2[x]) || (s1[x] < s2[x]))
			return(-1);
		x++;		
	}
	return (0);
}

int scan_input(char *st)
{
	char	*list[13];
	int		x;

	x = 0;
	list[0] = "sa\n"; 
	list[1] = "pa\n"; 
	list[2] = "ra\n"; 
	list[3] = "rb\n"; 
	list[4] = "rr\n"; 
	list[5] = "rra\n"; 
	list[6] = "rrb\n"; 
	list[7] = "rrr\n"; 
	list[8] = "sa\n"; 
	list[9] = "pb\n"; 
	list[10] = "sb\n"; 
	list[11] = "ss\n"; 
	list[12] = NULL; 
	while (x < 12)
	{
		if (ft_strcmp(list[x], st) == 0)
			return(0);
		x++;		
	}
	return(1);
}
void validate(t_var *vars)
{
	(void)vars;
	int	fd;
	int	fd1;
	char s;
	char *st;
	
	fd = open("commands", O_RDWR | O_TRUNC);
	fd1 = open("commands", O_RDONLY);
	while (read(0, &s, 1))
	{
		write(fd, &s, 1);
		if (s == '\n')
		{
			st = get_next_line(fd1);
			if (scan_input(st) == 1)
			{
				close(fd);
				close(fd1);
				exit_prog(&vars->stack_a);
			}
		}
	}
	close(fd);
	close(fd1);
}

int	main(int ac, char **av)
{
	t_var	vars;
	int 	fd;

	fd = 0;
	if (ac < 2)
		return (0);
	full_scan(av, &vars.stack_a);
	vars.stack_b = NULL;
	vars.stack_a = NULL;
	create_list_all(&vars.stack_a, av);
	check_dup_and_exit(&vars);
	validate(&vars);
	fd = open("commands",O_RDONLY);
	char *rd;
	rd = get_next_line(fd);
	while (rd)
	{
		if (ft_strcmp(rd, "sa\n") == 0)
			do_sa(&vars.stack_a);
		else if (ft_strcmp(rd, "sb\n") == 0)
			do_sb(&vars.stack_a);
		else if (ft_strcmp(rd, "ss\n") == 0)
			do_ss(&vars.stack_a, &vars.stack_b);
		else if (ft_strcmp(rd, "pa\n") == 0)
			do_pa(&vars.stack_a, &vars.stack_a);
		else if (ft_strcmp(rd, "pb\n") == 0)
			do_pb(&vars.stack_b, &vars.stack_a);
		else if (ft_strcmp(rd, "ra\n") == 0)
			do_ra(&vars.stack_a);
		else if (ft_strcmp(rd, "rb\n") == 0)
			do_rb(&vars.stack_a);
		else if (ft_strcmp(rd, "rr\n") == 0)
			do_rr(&vars.stack_a, &vars.stack_b);
		else if (ft_strcmp(rd, "rra\n") == 0)
			do_rra(&vars.stack_a);
		else if (ft_strcmp(rd, "rrb\n") == 0)
			do_rrb(&vars.stack_a);
		else if (ft_strcmp(rd, "sa\n") == 0)
			do_rrr(&vars.stack_a, &vars.stack_b);
		rd = get_next_line(fd);
	}
	if (check_sort(vars.stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (vars.stack_a)
		free_list(&vars.stack_a);
	if (vars.stack_b)
		free_list(&vars.stack_b);
	return (0);
}
