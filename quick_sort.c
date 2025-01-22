/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:35:16 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/17 12:35:17 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int	closest_operation(stack *stk, int node, int stk_size)
{
	int	i;

	i = 0;
	if (stk->index == node)
		return (0);
	if (stk->next->index == node)
		return (1);
	while (stk)
	{
		if (stk->index == node)
			break ;
		stk = stk->next;
		i++;
	}
	if (i < stk_size / 2)
		return (2);
	return (3);
}
void	sorted_stack_a(stack **stack_a, stack **stack_b)
{
	while (*stack_b)
	{
		push_stack(stack_b, stack_a, PA);
	}
}
void	sort_stack(stack **stack_a, stack **stack_b)
{
	int	size;
	int	index;
	int	op;

	size = stack_size(*stack_a);
	index = 0;
	while (*stack_a)
	{
		ft_puts("here ?\n");
		op = closest_operation(*stack_a, index, size);
		if (op == 0)
		{
			push_stack(stack_a, stack_b, PB);
			index++;
		}
		if (op == 1)
			swap_stack(stack_a, SA);
		else if (op == 2)
			rotate_stack(stack_a, RA);
		else if (op == 3)
			reverse_rotate_stack(stack_a, RRA);
	}
	sorted_stack_a(stack_a, stack_b);
}

