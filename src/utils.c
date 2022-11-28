#include "push_swap.h"

/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* exit_error:
*   Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
long int	ft_atoii(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

/* ft_putstr:
*	Prints a given string of characters to the standard output.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
void	exit_prog(t_stack **head)
{
	write(2, "Error\n", 6);
	free_list(head);
	exit(1);
}
void	free_func(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
void free_list(t_stack **store)
{
	t_stack	*tmp;

   while (*store)
    {
       tmp = *store;
       *store = (*store)->next;
       free(tmp);
    }
}

int		ft_atoi(const char *str, t_stack **head, char **bunch)
{
	int x;
	int sign;
	long long	res;
	long long	copy;

	x = 0;
	res = 0;
	sign = 1;
	while (str[x] == ' ' || str[x] == '\n'
		|| str[x] == '\t'
		|| str[x] == '\v' || str[x] == '\r'
		|| str[x] == '\f')
		x++;
	if (str[x] == '-' || str[x] == '+')
		sign = 1 - 2 * (str[x++] == '-');
	while ((str[x] >= '0' && str[x] <= '9'))
	{
		copy = res;	
		res = (res * 10) + (str[x++] - '0');
		// ft_printf("copy: |%d|\n", copy);
		// ft_printf("res: |%d|\n", res);
		if (copy > res)
		{
			free_func(bunch);
			exit_prog(head);
		}
	}
	if (res > INT_MAX && sign == 1)
	{
		free_func(bunch);
		exit_prog(head);
	}
	if ((res - 1) > INT_MAX && sign == -1)
	{
		free_func(bunch);
		exit_prog(head);
	}
	// ft_printf("values: |%d|\n", res);
	// free_list(head);
	return (res * sign);
}