/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:46:38 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/22 19:00:29 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str )
{
	int		x;
	int		sign;
	long	res;

	x = 0;
	res = 0;
	sign = 1;
	while (str[x] == ' ' || str[x] == '\n'
		|| str[x] == '\t'
		|| str[x] == '\v' || str[x] == '\r'
		|| str[x] == '\f')
		x++;
		
	if (str[x] == '-' || str[x] == '+')
		sign = 1 - 2 * (str[x++] == '-'); //hakuna matataaa
	while ((str[x] >= '0' && str[x] <= '9'))
		res = (res * 10) + (str[x++] - '0');
	if (res > INT_MAX && sign == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if ((res - 1) > INT_MAX && sign == -1)
	{
		write(2, "Error\n", 6);
		exit(1);	
	}
	ft_printf("last: %d\n",(res * sign));
	return (res * sign);
}
