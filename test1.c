/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/20 14:21:39 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*tmp;

	if ((*head) != NULL)
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

	if ((*head) && (*head)->next)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
}

void	ss(t_list **head)
{
	sa(head);
	sb(head);
}
// void pa(t_list *head)
// {
	
// }
// void pb(t_list *head)
// {
	
// }