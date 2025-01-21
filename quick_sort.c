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


/*
 * N <--(1)<-->(2)<-->(5)-->N
 * */
void	swap_nodes(stack *node1, stack *node2)
{
	stack	*tmp;

	tmp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = tmp;
	tmp = node1->next;
	node1->next = node2->next;
	node2->next = tmp;
	tmp = node1;
	node1 = node2;
	node2 = tmp;
}

stack	*get_last_node(stack *stk)
{
	while (stk->next)
		stk = stk->next;
	return (stk);
}
int	partition(stack *stk)
{
	stack	*pivot;
	stack	*i;
	stack	*j;

	pivot = stk;
	i = stk->next;
	j = get_last_node(stk);
	while (1)
	{
		while (i->data )
	}
}
