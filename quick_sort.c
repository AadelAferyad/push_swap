/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:35:16 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 09:34:54 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>



static void	sort_three_node(stack **stack_a)
{
	stack	*tmp;
	int	small;
	int	big;

	small = small_index(*stack_a);
	big = max_index(*stack_a);

	if (big == (*stack_a)->next->index)
		swap_stack(stack_a, SA);
	if (big == (*stack_a)->index)
		rotate_stack(stack_a, RA);
	if (small == (*stack_a)->next->next->index)
		reverse_rotate_stack(stack_a, RRA);
	if (small == (*stack_a)->next->index)
		swap_stack(stack_a, SA);
}

static void	push_to_target(stack **stack_a, stack **stack_b, int index)
{
	int	i;
	int	moves;

	i = 0;
	moves = index > 0 ? index : index * -1;
	while (i < moves)
	{
		if (index > 0)
			rotate_stack(stack_a, RA);
		else if (index < 0)
			reverse_rotate_stack(stack_a, RRA);
		i++;
	}
	push_stack(stack_b, stack_a, PA);
}

static int	is_sorted(stack *stk)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = stack_size(stk);
	while (stk)
	{
		if (i && tmp > stk->data)
			return (1);
		tmp = stk->data;
		stk = stk->next;
		i++;
	}
	return (0);
}

static void	push_b_to_a(stack **stack_a, stack **stack_b)
{
	int	target;
	int	moves;

	sort_three_node(stack_a);
	while (*stack_b)
	{
		target = find_right_position(*stack_a, (*stack_b)->index, 1);
		target = index_of_node(*stack_a, target);
		push_to_target(stack_a, stack_b, target);
	}
	while (is_sorted(*stack_a))
	{
		target = index_of_node(*stack_a, 0);
		moves = target > 0 ? target : target * -1;
		while (moves > 0)
		{
			if (target > 0)
				rotate_stack(stack_a, RA);
			else if (target < 0)
				reverse_rotate_stack(stack_a, RRA);
			moves--;
		}
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
	while (size > 3)
	{
		/*print_stack(*stack_b);*/
		find_best_op(*stack_a, *stack_b);
		adjust_push(stack_a, stack_b);
		i++;
		size--;
	}
	push_b_to_a(stack_a, stack_b);
}
