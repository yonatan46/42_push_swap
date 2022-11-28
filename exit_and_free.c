/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:51:05 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/28 17:56:31 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	*store = 0;
}

void	exit_prog(t_list **head)
{
	write(2, "Error\n", 6);
	free_list(head);
	exit(1);
}
