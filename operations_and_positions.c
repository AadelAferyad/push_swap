/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_and_positions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:19:47 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:16:13 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * stack_b_operations - finding the target in stack b
 * 	which will be right to push the current index to it
 * @stack_b: pointer to the stack b
 * @index: current index we trying to calculate number of moves it need
 * Return: return the biggest index on stack b if index is the new big index
 * 	otherwise the target which is close to index
 * */

int	stack_b_operations(t_stack *stack_b, int index)
{
	t_stack	*head;
	int		position;
	int		i;

	i = is_big_or_small(stack_b, index);
	head = stack_b;
	if (i == 1)
		return (biggest_num(stack_b));
	i = find_right_position(stack_b, index, 0);
	position = index_of_node(stack_b, i);
	return (position);
}

/*
 * set_operations - seting the number of operation each node need to be pushed
 * 	to stack B
 * @stack_a: pointer to the stack A
 * @stack_b: pointer to the stack B
 * */

void	set_operations(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;

	head = stack_a;
	while (stack_a)
	{
		stack_a->op = closest_operation(head, stack_b, stack_a->index) + 1;
		stack_a = stack_a->next;
	}
}

/*
 * find_best_op - searching for the cheapest operation
 * @stack_a: pointer to the stack A
 * @stack_b: pointer to the stack B
 * */

void	find_best_op(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head;
	t_stack	*tmp;
	int		op;

	head = stack_a;
	unset_operation(stack_a);
	set_operations(stack_a, stack_b);
	tmp = head;
	while (head)
	{
		if (head->op < tmp->op)
			tmp = head;
		head = head->next;
	}
	op = tmp->op;
	unset_operation(stack_a);
	tmp->op = op;
}
