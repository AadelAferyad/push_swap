/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_and_positions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:19:47 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 00:32:10 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_right_position(stack *stk, int index, int big_or_small)
{
	stack	*head;
	int		*arr;
	int		i;
	int		size;

	head = stk;
	i = MIN_INT;
	if (big_or_small == 1)
		i = MAX_INT;
	while (big_or_small && head)
	{
		if (head->index > index && head->index < i)
			i = head->index;
		head = head->next;
	}
	head = stk;
	while (!big_or_small && head)
	{
		if (head->index < index && i < head->index)
			i = head->index;
		head = head->next;
	}
	if (i == MAX_INT)
		i = lowest_index(stk);
	return (i);
}

int	stack_b_operations(stack *stack_b, int index)
{
	stack	*head;
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

int	closest_operation(stack *stack_a, stack *stack_b, int index)
{
	int	op_a;
	int	op_b;

	op_a = index_of_node(stack_a, index);
	op_b = stack_b_operations(stack_b, index);
	if (op_b <= 0 && op_a <= 0)
	{
		op_b *= -1, op_a *= -1;
		return (op_b > op_a ? op_b : op_a);
	}
	if (op_b >= 0 && op_a >= 0)
		return (op_b > op_a ? op_b : op_a);
	if ((op_b <= 0 && op_a >= 0) )
	{
		op_b *= -1;
		return (op_b + op_a);
	}
	if ((op_b >= 0 && op_a <= 0))
	{
		op_a *= -1;
		return (op_b + op_a);
	}
	return (op_b > op_a ? op_b : op_a);
}

void	set_operations(stack *stack_a, stack *stack_b)
{
	stack	*head;

	head = stack_a;
	while (stack_a)
	{
		stack_a->op = closest_operation(head, stack_b, stack_a->index) + 1;
		stack_a = stack_a->next;
	}
}

void	find_best_op(stack *stack_a, stack *stack_b)
{
	stack	*head;
	stack	*tmp;
	int	op;

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
