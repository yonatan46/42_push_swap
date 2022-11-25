/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/24 17:45:47 by yonamog2         ###   ########.fr       */
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
	int		x;

	if (*head_b)
	{
		x = (*head_b)->content;
		copy = (*head_b)->next;
		free(*head_b);
		(*head_b) = copy;
		ft_lstadd_front(head_a, ft_lstnew(x));
	}
}

void	pb(t_list **head_b, t_list **head_a)
{
	t_list	*copy;

	if ((*head_a))
	{
		copy = (*head_a)->next;
		ft_lstadd_front(head_b, ft_lstnew((*head_a)->content));
		free((*head_a));
		(*head_a) = copy;
	}
}
