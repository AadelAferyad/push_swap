/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turky_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:35:16 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/11 18:04:20 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * sort_three_node - sort three node in ascending order
 * @stack_a: double pointer to head of stack
 * */

static void	sort_three_node(t_stack **stack_a)
{
	int		small;
	int		big;

	small = lowest_index(*stack_a);
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

/*
 * push_to_target - rotates or reverse rotate stack A
 *	till the target is on the top of the stack B 
 * 	then push the node from stack B to it
 * @stack_a: double pointer to head of stack A
 * @stack_b: double pointer to head of stack B
 * index: current index of the stack_b node
 * */

static void	push_to_target(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;
	int	moves;

	i = 0;
	if (index > 0)
		moves = index;
	else
		moves = index * -1;
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

/*
 * is_sorted - check if the stack is sorted in ascending order
 * @stk: double pointer to head of stack
 * Return: returns 0 if sorted otherwise 1
 * */

int	is_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		if (stk->index != i)
			return (1);
		stk = stk->next;
		i++;
	}
	return (0);
}

/*
 * push_b_to_a - push all the node from stack b to the stack a and sorted
 * @stack_a: double pointer to head of stack A
 * @stack_b: double pointer to head of stack B
 * */

static void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
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
		moves = target;
		if (target < 0)
			moves = target * -1;
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

/*
 * sort_stack - sort stack A
 * @stack_a: double pointer to head of stack A
 * @stack_b: double pointer to head of stack B
 * */

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		i;

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
	while (size > 3)
	{
		find_best_op(*stack_a, *stack_b);
		adjust_push(stack_a, stack_b);
		i++;
		size--;
	}
	push_b_to_a(stack_a, stack_b);
}
