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
	return (i <= (size / 2) ? i : (i * -1));
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
	printf("this is the biggest num in stack_b (%d)[%d]\n", tmp->data, tmp->index);
	return (index_of_node(head, tmp->index));
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

/*
 * 9 3 1 2 0 8
 * 0 1 2 3 8 9
 * */
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	closest_index(int *arr, int size, int index, stack *stk)
{
	int	i;
	int	max;
	int	low;

	i = 0;
	while (i < size)
	{
		if (arr[i] < index)
		{
			printf("arr[low] %d index : %d\n", low, index);
			low = arr[i];
		}
		else if (arr[i] > index)
		{
			max = arr[i];
		}
		i++;
	}
	printf("low : %d max : %d\n", low, max);
	if (index - low < max - index)
		return (low);
	printf("max \n");
	return (max);
}

int	find_right_position(stack *stk, int index)
{
	int	i;
	int	size;
	int	*arr;
	stack	*head;

	size = stack_size(stk);
	arr = ft_calloc(sizeof(int), size);
	head = stk;
	while (stk)
	{
		arr[i] = stk->index;
		stk = stk->next;
		i++;
	}
	sort_array(arr, size);
	i = 0;
	while (i < size)
	{
		printf("arr %d ", arr[i]);
		i++;
	}
	printf("\n");
	i = closest_index(arr, size, index, head);
	free(arr);
	return (i);
}

int	stack_b_operations(stack *stack_b, int index)
{
	stack	*head;
	int	position;
	int	i;

	i = is_big_or_small(stack_b, index);
	head = stack_b;
	if (i == 1 || !i)
	{
		printf("FOUDN THE SMALLEST IN STACK B %d\n\n", index);
		return (biggest_num(stack_b));
	}
	i = find_right_position(stack_b, index);
	position = index_of_node(head, i);
	printf("the biggest one: %d index : %d position : %d\n", i, index, position);
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
	printf("%d %d\n", tmp->index, tmp->op);
	printf("called \n");
	op_a = index_of_node(*stack_a, tmp->index);
	op_b = stack_b_operations(*stack_b, tmp->index);
	while (i < tmp->op - 1)
	{
		print_stack(*stack_b);
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
			reverse_rotate_stack(stack_b, RRB);
	   i++;
	}
	push_stack(stack_a, stack_b, PB);
}
void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;
	int	i;
	stack	*head;

	push_stack(stack_a, stack_b, PB);
	push_stack(stack_a, stack_b, PB);
	size = stack_size(*stack_a);
	head = *stack_a;
	print_stack(*stack_a);
	print_stack(*stack_b);
	i = 0;
	while (size > 3)
	{
		print_stack(*stack_b);
		find_best_op(*stack_a, *stack_b);
		adjust_push(stack_a, stack_b);
		i++;
		size--;
	}
	print_stack(*stack_b);
}
