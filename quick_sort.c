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

int	closest_operation(stack *stk, int node, int stk_size)
{
	int	i;

	i = 0;
	if (!stk)
		return (10);
	if (stk->index == node)
		return (0);
	if (stk->next && stk->next->index == node)
		return (1);
	while (stk)
	{
		if (stk->index == node)
			break ;
		stk = stk->next;
		i++;
	}
	if (i < (stk_size / 2))
		return (2);
	return (3);
}
int	max_index(stack *stk)
{
	int	index;

	index = stk->index;
	while (stk)
	{
		if (stk->index > index)
			index = stk->index;
		stk = stk->next;
	}
	return (index);
}


void	sorted_stack_a(stack **stack_a, stack **stack_b, int size)
{
	int	index;
	int	op;

	index = max_index(*stack_b);
	while (*stack_b)
	{
		op = closest_operation(*stack_b, index, size);
		print_stack(*stack_b);
		printf("stack a indexx : %d\n", index);
		print_stack(*stack_a);
		if (!op)
		{
			push_stack(stack_b, stack_a, PA);
			index--;
		}
		else if (op == 1)
			swap_stack(stack_b, SB);
		else if (op == 2)
			rotate_stack(stack_b, RB);
		else if (op == 3)
			reverse_rotate_stack(stack_b, RRB);
	}
}
/*
 * (0)-->(2)-->(1)-->
 * */
void	optimize_sort(stack **stk, int low, int high, int size)
{
	int	op;
	int	op1;

	op = closest_operation(*stk, low, size);
	op1 = closest_operation(*stk, high, size);

	if (op == 1 || op1 == 1)
		swap_stack(stk, SA);
	else if (op == 2 || op1 == 2)
		rotate_stack(stk, RA);
	else if (op == 3 || op1 == 3)
		reverse_rotate_stack(stk, RRA);
}

void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;

	push_stack(stack_a, stack_b, PB);
	push_stack(stack_a, stack_b, PB);
	size = stack_size(*stack_a);
	while (size > 3)
	{
	}
}
