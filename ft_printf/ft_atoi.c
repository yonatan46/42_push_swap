/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:46:38 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/24 03:04:29 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_prog(t_list **head)
{
	write(2, "Error\n", 6);
	free_list(head);
	exit(1);
}
void free_list(t_list **store)
{
	t_list	*tmp;

   while (*store)
    {
       tmp = *store;
       *store = (*store)->next;
       free(tmp);
    }
}

int		ft_atoi(const char *str, t_list **head, char **bunch)
{
	int x;
	int sign;
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
		// ft_printf("copy: |%d|\n", copy);
		// ft_printf("res: |%d|\n", res);
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
	// ft_printf("values: |%d|\n", res);
	// free_list(head);
	return (res * sign);
}
