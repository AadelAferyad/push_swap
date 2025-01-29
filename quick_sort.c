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

int	closest_operation(stack *stack_a, stack *stack_b, int index)
{
	stack	*head;
	int	size;
	int	i;

	i = 0;
	size = stack_size(stack_a);
	head = stack_a;
	while (head)
	{
		if (head->index == index)
			break ;
		i++;
		head = head->next;
	}

}

void	set_operations(stack *stack_a, stack *stack_b)
{
	while (stack_a)
	{
		stack_b->op = closest_operation(stack_a, stack_b, stack_a->index);
		
	}
}

void	find_best_op(stack **stack_a, stack **stack_b)
{
	stack	*head;

	head = *stack_a;
	unset_operation(*stack_a);
	set_operations(*stack_a, *stack_b);
	while (head)
	{
	}
}

void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;

	push_stack(stack_a, stack_b, PB);
	push_stack(stack_a, stack_b, PB);
	size = stack_size(*stack_a);
	while (size > 3)
	{
		find_best_op(stack_a, stack_b);
	}
}
