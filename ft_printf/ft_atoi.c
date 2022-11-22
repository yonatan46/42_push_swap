/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:46:38 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/22 17:57:26 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, t_list **list)
{
	(void)list;
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
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while ((str[x] >= '0' && str[x] <= '9') && (res <= INT_MAX))
		res = (res * 10) + (str[x++] - '0');
	if (res > INT_MAX && sign == 1)
		return (-1);
	if (res > INT_MAX && sign == -1)
		return (-1);
	ft_printf("ft_atoi: %d\n",(res * sign));
	return (res * sign);
}
