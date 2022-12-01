/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:16:18 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/01 22:41:56 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define BUFFER_SIZE 1


char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_remain(char *left);
char	*ft_full_str(int fd, char *store);
char	*ft_get_line(char *all);
char	*get_next_line(int fd);

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

int			check_sort(t_list *stack);
t_list		*get_stack_bottom(t_list *stack);
t_list		*get_stack_before_bottom(t_list *stack);
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
int			ft_atoi(const char *str, t_list **head, char **bunch);
void		ft_putstr(char *str);
void		exit_prog(t_list **head);
void		free_func(char **args);
void		free_list(t_list **store);
char		**ft_split(const char *s, char c);
int			create_list_all(t_list **data, char **av);
int			full_scan(char **av, t_list **head);
int			check_duplicate(t_list **stack_a);
size_t		ft_strlen(const char *s);
char		*ft_strdup(char *s1);
int			ft_isprint(int c);

#endif