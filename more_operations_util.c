/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:45:01 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/11 18:07:12 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * unset_operation - converting all tha stack op variable to zero
 * @stk: pointer to the stack
 * */

void	unset_operation(t_stack *stk)
{
	if (!stk)
		return ;
	while (stk)
	{
		stk->op = 0;
		stk = stk->next;
	}
}

/*
 * closest_operation_helper - function helper for closest_operation
 * @op_a: number of operation in stack A
 * @op_b: number of operation in stack B
 * @flag: flag var to check whether op_a and op_b and negatives
 * Return: return op_b if it's greater then op_a otherwise op_a
 * */

static int	closest_operation_helper(int op_a, int op_b, int flag)
{
	if (flag == 1)
	{
		op_b *= -1;
		op_a *= -1;
	}
	if (op_b > op_a)
		return (op_b);
	return (op_a);
}

/*
 * closest_operation - return the number of moves
 * 	a node needs to be pushed in the right position
 * @stack_a: pointer which hold address of the stack a
 * @stack_b: pointer which hold address of the stack b
 * @index: current index we trying to push
 * Return: return op_b if it's greater then op_a otherwise op_a
 * */

int	closest_operation(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	op_a;
	int	op_b;

	op_a = index_of_node(stack_a, index);
	op_b = stack_b_operations(stack_b, index);
	if (op_b <= 0 && op_a <= 0)
		return (closest_operation_helper(op_a, op_b, 1));
	if (op_b >= 0 && op_a >= 0)
		return (closest_operation_helper(op_a, op_b, 0));
	if ((op_b <= 0 && op_a >= 0))
	{
		op_b *= -1;
		return (op_b + op_a);
	}
	if ((op_b >= 0 && op_a <= 0))
	{
		op_a *= -1;
		return (op_b + op_a);
	}
	if (op_b > op_a)
		return (op_b);
	return (op_a);
}

/*
 * find_right_position - searching for the right target of current index
 * @stk: pointer which hold address of the stack
 * @index: current index we trying to push
 * @big_or_small: flag variable to see if we locking for the lowest closest index
 * 	or the greater closest index
 * Return: returns the target index
 * */

int	find_right_position(t_stack *stk, int index, int big_or_small)
{
	t_stack	*head;
	int		i;

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
