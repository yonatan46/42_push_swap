/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:41:47 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/21 14:17:51 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*tmp;
	t_list	*cra;

	if (lst && del)
	{
		tmp = NULL;
		while (lst)
		{
			cra = ft_lstnew((f)(lst->content));
			if (!cra)
			{
				ft_lstclear(&cra, del);
				return (NULL);
			}
			ft_lstadd_back(&tmp, cra);
			lst = lst->next;
		}
		return (tmp);
	}
	return (NULL);
}
