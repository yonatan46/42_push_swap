/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/26 19:08:14 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*tmp;

	if ((*head))
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

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*copy;
	t_list	*tmp1;

	if ((*head_b))
	{
		copy = (*head_b);
		tmp1 = (*head_b)->next;
		(*head_b) = tmp1;
		ft_lstadd_front(head_a, copy);
	}
}

void	pb(t_list **head_b, t_list **head_a)
{
	t_list	*copy;
	t_list	*tmp1;

	if ((*head_a))
	{
		copy = (*head_a);
		tmp1 = (*head_a)->next;
		(*head_a) = tmp1;
		ft_lstadd_front(head_b, copy);
	}
}
