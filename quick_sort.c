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
	int	range;
	int	i;
	int	j;

	size = stack_size(*stack_a);
	range = size/5;
	i = 0;
	index = 0;
	j = 0;
	while (i < 5)
	{
		while (j < range)
		{
			if ((*stack_a)->index <)
		}
		i++;
	}
	index = 0;
}

