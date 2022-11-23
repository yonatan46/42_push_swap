/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/24 03:43:57 by yonamog2         ###   ########.fr       */
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

// void	pa(t_list **head_a, t_list **head_b)
// {
// 	t_list	*copy;
	
// 	if ((*head_b)->next)
// 	{
		
// 	}
// }

// void	pb(t_list **head_b, t_list **head_a)
// {
// 	t_list	*copy;

// 	if ((*head_a)->next)
// 	{
// 		copy = (*head_a)->next;
// 		ft_lstadd_front(head_b, ft_lstnew((*head_a)->content));
// 		free((*head_a));
// 		(*head_a) = copy;
// 	}
// }
