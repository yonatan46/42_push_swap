/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:08 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 18:25:31 by yonamog2         ###   ########.fr       */
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

void	check_atoi(t_atoi *vars, t_list **head, char **bunch)
{
	if (vars->res > INT_MAX && vars->sign == 1)
	{
		free_func(bunch);
		exit_prog(head);
	}
	if ((vars->res - 1) > INT_MAX && vars->sign == -1)
	{
		free_func(bunch);
		exit_prog(head);
	}
}

int	ft_atoi(const char *str, t_list **head, char **bunch)
{
	t_atoi	vars;

	vars.x = 0;
	vars.res = 0;
	vars.sign = 1;
	while (str[vars.x] == ' ' || str[vars.x] == '\n'
		|| str[vars.x] == '\t'
		|| str[vars.x] == '\v' || str[vars.x] == '\r'
		|| str[vars.x] == '\f')
		vars.x++;
	if (str[vars.x] == '-' || str[vars.x] == '+')
		vars.sign = 1 - 2 * (str[vars.x++] == '-');
	while ((str[vars.x] >= '0' && str[vars.x] <= '9'))
	{
		vars.copy = vars.res;
		vars.res = (vars.res * 10) + (str[vars.x++] - '0');
		if (vars.copy > vars.res)
		{
			free_func(bunch);
			exit_prog(head);
		}
	}
	check_atoi(&vars, head, bunch);
	return (vars.res * vars.sign);
}

void	free_list(t_list **store)
{
	t_list	*tmp;

	if (!store || !(*store))
		return ;
	while (*store)
	{
		tmp = *store;
		*store = (*store)->next;
		free(tmp);
	}
	*store = NULL;
}

void	exit_prog(t_list **head)
{
	write(2, "Error\n", 6);
	free_list(head);
	exit(1);
}
