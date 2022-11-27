/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/27 18:37:48 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	t_list	*tmp1;

	if ((*head)->next)
	{
		tmp1 = (*head);
		tmp = (*head)->next;
		(*head) = tmp;
		copy = (*head);
		tmp1->next = NULL;
		copy = (*head);
		while (copy->next)
		{
			copy = copy->next;
		}
		copy->next = tmp1;
	}
}

void	rb(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	t_list	*tmp1;

	if ((*head)->next)
	{
		tmp1 = (*head);
		tmp = (*head)->next;
		(*head) = tmp;
		copy = (*head);
		tmp1->next = NULL;
		copy = (*head);
		while (copy->next)
			copy = copy->next;
		copy->next = tmp1;
	}
}

void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	ra(head_b);
}

void	rra(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	t_list	*tmp1;

	if ((*head)->next)
	{
		tmp = (*head);
		while (tmp->next->next)
			tmp = tmp->next;
		copy = tmp->next;
		tmp->next = NULL;
		tmp1 = (*head);
		copy->next = tmp1;
		(*head) = copy;
	}
}

void	rrb(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	t_list	*tmp1;

	if ((*head)->next)
	{
		tmp = (*head);
		while (tmp->next->next)
			tmp = tmp->next;
		copy = tmp->next;
		tmp->next = NULL;
		tmp1 = (*head);
		copy->next = tmp1;
		(*head) = copy;
	}
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rra(head_b);
}