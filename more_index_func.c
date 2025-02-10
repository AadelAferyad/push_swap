/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_index_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:12:51 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 00:32:08 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	return (max);
}

void	indexing_stack(stack *stk)
{
	stack	*tmp;
	stack	*head;
	stack	*n;
	int	index;

	index = 0;
	head = stk;
	while (stk)
	{
		index = 0;
		n = stk;
		tmp = head;
		while (tmp)
		{
			if (tmp->data < n->data)
				index++;
			tmp = tmp->next;
		}
		n->index = index;
		stk = stk->next;
	}
}

int	stack_size(stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}
