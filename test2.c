/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:16:15 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/24 17:28:17 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	int		x;
	int		res;

	if ((*head))
	{
		x = ft_lstsize((*head));
		res = (*head)->content;
		tmp = (*head)->next;
		copy = 0;
		while (--x && tmp)
		{
			ft_lstadd_back(&copy, ft_lstnew(tmp->content));
			tmp = tmp->next;
		}
		ft_lstadd_back(&copy, ft_lstnew(res));
		free_list(head);
		(*head) = copy;
	}
	
}

void	rb(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	int		x;
	int		res;

	if ((*head))
	{
		x = ft_lstsize((*head));
		res = (*head)->content;
		tmp = (*head)->next;
		copy = 0;
		while (--x && tmp)
		{
			ft_lstadd_back(&copy, ft_lstnew(tmp->content));
			tmp = tmp->next;
		}
		ft_lstadd_back(&copy, ft_lstnew(res));
		free_list(head);
		(*head) = copy;
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
	int		x;
	int		res;

	if ((*head))
	{
		x = ft_lstsize((*head));
		tmp = (*head);
		copy = 0;
		while (tmp->next)
			tmp = tmp->next;
		res = tmp->content;
		tmp = (*head);
		ft_lstadd_back(&copy, ft_lstnew(res));
		while (x-- && tmp->next)
		{
			ft_lstadd_back(&copy, ft_lstnew(tmp->content));
			tmp = tmp->next;
		}
		free_list(head);
		(*head) = copy;
	}
	
}

void	rrb(t_list **head)
{
	t_list	*copy;
	t_list	*tmp;
	int		x;
	int		res;

	if (*head)
	{
		x = ft_lstsize((*head));
		tmp = (*head);
		copy = 0;
		while (tmp->next)
			tmp = tmp->next;
		res = tmp->content;
		tmp = (*head);
		ft_lstadd_back(&copy, ft_lstnew(res));
		while (x-- && tmp->next)
		{
			ft_lstadd_back(&copy, ft_lstnew(tmp->content));
			tmp = tmp->next;
		}
		free_list(head);
		(*head) = copy;
	}
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rra(head_b);
}