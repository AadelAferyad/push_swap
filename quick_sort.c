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
	int	j;
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
	j = size - i;
	if (j < i)
		return (j * -1);
	return (i);
}
int	is_big(stack *stk, int index)
{
	while (stk)
	{
		if (stk->index > index)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	is_small(stack *stk, int index)
{
	while (stk)
	{
		if (stk->index < index)
			return (0);
		stk = stk->next;
	}
	return (1);
}
int	is_big_or_small(stack *stk, int index)
{
	int	big;
	int	small;

	big = 0;
	small = 0;
	if (!index)
		return (1);
	big = is_big(stk, index);
	small = is_small(stk, index);
	if (big || small)
		return (1);
	return (2);
}
int	biggest_num(stack *stk)
{
	stack	*tmp;
	stack	*head;
	int	max;

	tmp = stk;
	head = stk;
	while (stk)
	{
		if (stk->data > tmp->data)
			tmp = stk;
		stk = stk->next;
	}
	max = index_of_node(head, tmp->index);
	/*printf("this is the biggest num in stack_b (%d)[%d] position : %d\n", tmp->data, tmp->index, max);*/
	return (max);
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
	int	low;

	i = 0;
	low = 0;
	while (i < size)
	{
		if (arr[i] < index)
			low = arr[i];
		i++;
	}
	/*printf("insed closest_index : %d | low : %d\n", low, index);*/
	return (low);
}

int	find_right_position(stack *stk, int index)
{
	int	i;
	int	size;
	int	*arr;
	stack	*head;

	size = stack_size(stk);
	i = 0;
	arr = ft_calloc(sizeof(int), size + 1);
	head = stk;
	while (stk)
	{
		arr[i] = stk->index;
		stk = stk->next;
		i++;
	}
	sort_array(arr, size);
	i = 0;
	/*while (i < size)*/
	/*{*/
	/*	printf("arr %d ", arr[i]);*/
	/*	i++;*/
	/*}*/
	/*printf("\n");*/
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
	if (i == 1)
	{
		/*printf("FOUDN THE SMALLEST IN STACK B %d\n\n", index);*/
		return (biggest_num(stack_b));
	}
	i = find_right_position(stack_b, index);
	position = index_of_node(stack_b, i);
	/*printf("the biggest one: %d index : %d position : %d\n", i, index, position);*/
	return (position);
}

int	closest_operation(stack *stack_a, stack *stack_b, int index)
{
	int	op_a;
	int	op_b;

	op_a = index_of_node(stack_a, index);
	op_b = stack_b_operations(stack_b, index);
	/*printf("op_a : %d | op_b : %d  | index : %d", op_a, op_b, index);*/
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
	/*printf("%d %d\n", tmp->index, tmp->op);*/
	/*printf("called \n");*/
	op_a = index_of_node(*stack_a, tmp->index);
	op_b = stack_b_operations(*stack_b, tmp->index);
	while (i < tmp->op - 1)
	{
		/*print_stack(*stack_b);*/
		/*printf("op_a : %d op_b : %d | index %d, n ops : %d\n",op_a, op_b, tmp->index, tmp->op);*/
		/*print_stack(*stack_a);*/
		if (op_a > 0 && op_b > 0)
		{
			op_a--;
			op_b--;
			rotate_both_stack(stack_a, stack_b);
		}
		else if (op_a < 0 && op_b < 0)
		{
			op_a++;
			op_b++;
			reverse_rotate_both_stack(stack_a, stack_b);
		}
		else if (op_a > 0)
		{
			rotate_stack(stack_a, RA);
			op_a--;
		}
		else if (op_a < 0)
		{
			reverse_rotate_stack(stack_a, RA);
			op_a++;
		}
		else if (op_b > 0)
		{
			op_b--;
			rotate_stack(stack_b, RB);
		}
		else if (op_b < 0)
		{
			op_b++;
			reverse_rotate_stack(stack_b, RRB);
		}
	   i++;
	}
	push_stack(stack_a, stack_b, PB);
}
int	small_index(stack *stk)
{
	int	i;

	i = stk->index;
	while (stk)
	{
		if (i > stk->index)
			i = stk->index;
		stk = stk->next;
	}
	return (i);
}

int	max_index(stack *stk)
{
	int	i;

	i = stk->index;
	while (stk)
	{
		if (i < stk->index)
			i = stk->index;
		stk = stk->next;
	}
	return (i);
}

void	sort_three_node(stack **stack_a)
{
	stack	*tmp;
	int	small;
	int	big;

	tmp = *stack_a;
	small = small_index(*stack_a);
	big = max_index(*stack_a);

	if (big == tmp->next->index)
		swap_stack(stack_a, RA);
	if (big == tmp->index)
		rotate_stack(stack_a, RA);
	if (small == tmp->next->next->index)	
		reverse_rotate_stack(stack_a, RRA);
	if (small == tmp->next->index)
		swap_stack(stack_a, SA);
}

void	push_b_to_a(stack **stack_a, stack **stack_b)
{
	stack	*head;
	int	target;

	sort_three_node(stack_a);
	while (*stack_b)
	{
		target = closest_index();

	}
}

void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;
	int	i;
	stack	*head;

	size = stack_size(*stack_a);
	i = 0;
	while (size > 3)
	{
		if (i == 2)
			break ;
		push_stack(stack_a, stack_b, PB);
		i++;
		size--;
	}
	head = *stack_a;
	/*print_stack(*stack_a);*/
	/*print_stack(*stack_b);*/
	while (size > 3)
	{
		/*print_stack(*stack_b);*/
		find_best_op(*stack_a, *stack_b);
		adjust_push(stack_a, stack_b);
		i++;
		size--;
	}
	push_b_to_a(stack_a, stack_b);
	print_stack(*stack_b);
}
