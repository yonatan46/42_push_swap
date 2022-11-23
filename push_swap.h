/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:04:16 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/24 03:01:25 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/libft.h"

int		create_list_all(t_list **data, char **av);
void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);
void	ra(t_list **head);
void	free_list(t_list **store);
void	rr(t_list **head_a, t_list **head_b);
void	rra(t_list **head);
void	rrb(t_list **head);
void	pb(t_list **head_b, t_list **head_a);
#endif