/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/23 07:05:18 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*tmp;

	if ((*head)->next)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
}

void	sb(t_list **head)
{
	t_list	*tmp;

	if ((*head)->next)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}
// void pa(t_list *head)
// {
	
// }
// void pb(t_list *head)
// {
	
// }