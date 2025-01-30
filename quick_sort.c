/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:35:16 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/27 19:16:17 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int	index_of_node(stack *stk, int index)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(stk);
	while (stk->next)
	{
		if (index == stk->index)
			break ;
		i++;
		stk = stk->next;
	}
	return (i < (size / 2) ? i : (i * -1));
}

int	is_big_or_small(stack *stk, int index)
{
	if (!index)
		return (0);
	while (stk)
	{
		if (stk->index > index)
			return (2);
		stk = stk->next;
	}
	return (1);
}
int	biggest_num(stack *stk)
{
	stack	*tmp;
	stack	*head;

	tmp = stk;
	head = stk;
	while (stk)
	{
		if (stk->data > tmp->data)
			tmp = stk;
		stk = stk->next;
	}
	return (index_of_node(head, tmp->index));
}


int	stack_b_operations(stack *stack_b, int index)
{
	stack	*head;
	int	position;
	int	i;

	i = is_big_or_small(stack_b, index);
	head = stack_b;
	if (i == 1 || !i)
		return (biggest_num(stack_b));
	while (stack_b)
	{
		if (stack_b->index < index)
			i = stack_b->index;
		stack_b = stack_b->next;
	}
	position = index_of_node(head, i);
	/*printf("inside stack_b position : %d\n", position);*/
	return (position);
}

int	closest_operation(stack *stack_a, stack *stack_b, int index)
{
	int	op_a;
	int	op_b;

	op_a = index_of_node(stack_a, index);
	op_b = stack_b_operations(stack_b, index);
	/*printf("op_a : %d | op_b : %d ", op_a, op_b);*/
	if (op_b <= 0 && op_a <= 0)
	{
		op_b *= -1;
		op_a *= -1;
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
		/*printf("| node: %d [%d] op : %d\n\n", stack_a->data, stack_a->index, stack_a->op);*/
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
	/*printf("node : %d [%d] n op : %d \n\n", tmp->data, tmp->index, tmp->op);*/
}

void	adjust_push(stack **stack_a, stack **stack_b)
{
	stack	*tmp;
	int	op_a;
	int	op_b;
	int	i;

	i = 0;
	tmp = *stack_a;
	while (!tmp->op)
		tmp = tmp->next;
	op_a = index_of_node(*stack_a, tmp->index);
	op_b = stack_b_operations(*stack_b, tmp->index);
	printf("%d %d\n", tmp->index, tmp->op);
	while (i < tmp->op - 1)
	{
		printf("op_a : %d op_b : %d\n",op_a, op_b);
		if (op_a > 0 && op_b > 0)
			rotate_both_stack(stack_a, stack_b);
		else if (op_a < 0 && op_b < 0)
			reverse_rotate_both_stack(stack_a, stack_b);
		else if (op_a > 0)
			rotate_stack(stack_a, RA);
		else if (op_a < 0)
			reverse_rotate_stack(stack_a, RA);
		else if (op_b > 0)
			rotate_stack(stack_b, RB);
		else if (op_b < 0)
			reverse_rotate_stack(stack_b, RB);
	   i++;
	}
	printf("here ?\n");
	push_stack(stack_a, stack_b, PB);
}
void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;
	stack	*head;

	push_stack(stack_a, stack_b, PB);
	push_stack(stack_a, stack_b, PB);
	size = stack_size(*stack_a);
	find_best_op(*stack_a, *stack_b);
	head = *stack_a;
	while (size > 3)
	{
		adjust_push(stack_a, stack_b);
		find_best_op(*stack_a, *stack_b);
		size--;
	}
}
