/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:16:18 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 18:17:57 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	int		x;
	int		z;
	int		y;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_var;

typedef struct s_atoi
{
	int			x;
	int			sign;
	long long	res;
	long long	copy;
}	t_atoi;

/* Sorting Algorithms */

int			check_sort(t_list *stack);
void		sort_three(t_list **stack);
void		sort(t_list **stack_a, t_list **stack_b);

/* Position */

int			get_lowest_index_position(t_list **stack);
void		get_target_position(t_list **stack_a, t_list **stack_b);

/* Calculate Move */
/* Cost */
void		get_cost(t_list **stack_a, t_list **stack_b);
void		do_cheapest_move(t_list **stack_a, t_list **stack_b);
void		do_move(t_list **a, t_list **b, int cost_a, int cost_b);

/* moves */

void		do_pa(t_list **stack_a, t_list **stack_b);
void		do_pb(t_list **stack_a, t_list **stack_b);
void		do_sa(t_list **stack_a);
void		do_sb(t_list **stack_b);
void		do_ss(t_list **stack_a, t_list **stack_b);
void		do_ra(t_list **stack_a);
void		do_rb(t_list **stack_b);
void		do_rr(t_list **stack_a, t_list **stack_b);
void		do_rrr(t_list **stack_a, t_list **stack_b);
void		do_rra(t_list **stack_a);
void		do_rrb(t_list **stack_b);

/* Stack Functions */

t_list		*get_stack_bottom(t_list *stack);
t_list		*get_stack_before_bottom(t_list *stack);
int			get_stack_size(t_list	*stack);

/* Utils */

int			ft_atoi(const char *str, t_list **head, char **bunch);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		exit_prog(t_list **head);
void		free_func(char **args);
void		free_list(t_list **store);
char		**ft_split(const char *s, char c);

int			create_list_all(t_list **data, char **av);
int			full_scan(char **av, t_list **head);
int			check_duplicate(t_list **stack_a);
void		init_full(t_list **head_a, t_list **head_b, char **av);
size_t		ft_strlen(const char *s);
char		*ft_strdup(char *s1);
int			ft_isprint(int c);

#endif