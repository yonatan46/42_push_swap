/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/20 14:56:09 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head)
{
	t_list *tmp;

	tmp = (*head);
	while (tmp->next)
	{
		if (tmp->next->next == NULL)
			tmp->next = NULL;
		tmp = tmp->next;
	}
	tmp->next = (*head);
}
// void rb(t_list *head)
// {
	
// }
// void rr(t_list *head)
// {
	
// }
// void rra(t_list *head)
// {
	
// }
// void rrb(t_list *head)
// {
	
// }
// void rrb(t_list *head)
// {
	
// }