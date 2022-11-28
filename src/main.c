
#include "push_swap.h"

/* check_sort:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	check_sort(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = get_stack_size(*stack_a);
	if (size == 2 && !check_sort(*stack_a))
		do_sa(stack_a);
	else if (size == 3)
		tiny_sort(stack_a);
	else if (size > 3 && !check_sort(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/

void set_index(t_stack **head)
{
	int x;
	t_stack *tmp;

	x = 1;
	tmp = (*head);
	while (tmp)
	{
		tmp->index = x;
		tmp = tmp->next;
		x++;
	}
}
void set_chunk_num(t_stack **head)
{
	int count;
	t_stack *tmp;
	t_stack *tmp1;
	
	tmp = (*head);
	while (tmp)
	{
		tmp1 = (*head);
		count = 1;
		while (tmp1)
		{
			if (tmp1->value < tmp->value)
				count++;
			tmp1 = tmp1->next;
		}
		tmp->index = count;
		tmp = tmp->next;
	}
}
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_stack	*tmp;
	int x;
	// int stack_size;

	if (ac < 2)
		return (0);
	full_scan(av, &stack_a);
	// if (!check_input(av))
	// 	exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = NULL;
	create_list_all(&stack_a, av);
	x = check_duplicate(&stack_a);
	if (x == 1)
	{
		if (stack_a)
			exit_prog(&stack_a);
	}
	if (check_sort(stack_a) == 1)
	{
		free_list(&stack_a);
		return(0);
	}
	// stack_a = fill_stack_values(ac, av);
	// stack_size = get_stack_size(stack_a);
	// assign_index(stack_a, stack_size + 1);
	set_chunk_num(&stack_a);
	push_swap(&stack_a, &stack_b);
	// tmp = stack_a;
	// while (tmp)
	// {
	// 	printf("val:\t%d index[%d]\n",tmp->value, tmp->index);
	// 	tmp = tmp->next;
	// }
	if (stack_a)
		free_list(&stack_a);
	if (stack_b)
		free_list(&stack_b);
	// free_stack(&stack_a);
	// free_stack(&stack_b);
	return (0);
}
