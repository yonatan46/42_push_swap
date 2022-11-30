/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:08 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/30 20:45:32 by yonamog2         ###   ########.fr       */
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


int		ft_atoi(const char *str, t_list **head, char **bunch)
{
	int			x;
	int			sign;
	long long	res;
	long long	copy;

	x = 0;
	res = 0;
	sign = 1;
	while (str[x] == ' ' || str[x] == '\n'
		|| str[x] == '\t'
		|| str[x] == '\v' || str[x] == '\r'
		|| str[x] == '\f')
		x++;
	if (str[x] == '-' || str[x] == '+')
		sign = 1 - 2 * (str[x++] == '-');
	while ((str[x] >= '0' && str[x] <= '9'))
	{
		copy = res;
		res = (res * 10) + (str[x++] - '0');
		if (copy > res)
		{
			free_func(bunch);
			exit_prog(head);
		}
	}
	if (res > INT_MAX && sign == 1)
	{
		free_func(bunch);
		exit_prog(head);
	}
	if ((res - 1) > INT_MAX && sign == -1)
	{
		free_func(bunch);
		exit_prog(head);
	}
	return (res * sign);
}
