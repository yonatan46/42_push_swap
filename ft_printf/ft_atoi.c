/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:46:38 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/23 00:14:34 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_prog(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str )
{
	t_tools	condition;
	long	res;

	condition.x = 0;
	res = 0;
	condition.sign = 1;
	while (str[condition.x] == ' ' || str[condition.x] == '\n'
		|| str[condition.x] == '\t'
		|| str[condition.x] == '\v' || str[condition.x] == '\r'
		|| str[condition.x] == '\f')
		condition.x++;
	if (str[condition.x] == '-' || str[condition.x] == '+')
		condition.sign = 1 - 2 * (str[condition.x++] == '-');
	while ((str[condition.x] >= '0' && str[condition.x] <= '9'))
		res = (res * 10) + (str[condition.x++] - '0');
	if (res > INT_MAX && condition.sign == 1)
		exit_prog();
	if ((res - 1) > INT_MAX && condition.sign == -1)
		exit_prog();
	return (res * condition.sign);
}
