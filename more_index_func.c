/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_index_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:12:51 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:14:19 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * index_of_node - searching for the position of index in a stack
 * @stk: pointer which hold address of the stack
 * @index: current index we trying to search it's position
 * Return: returns positive integer if position is less then stack size divided
 * 	by 2 otherwise negative integer
 * */

int	index_of_node(t_stack *stk, int index)
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

/*
 * is_big_or_small - checking if index is the new biggest index in the stack
 * 	or if it's the new lowest
 * @stk: pointer which hold address of the stack
 * @index: index to check in the stack
 * Return: returns 1 if true the index is the new lowest or the new biggest
 * 	on the stack otherwise 2
 * */

int	is_big_or_small(t_stack *stk, int index)
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

/*
 * biggest_num - checking for the biggest index on the stack
 * @stk: pointer which hold address of the stack
 * Return: returns the position of the biggest index on the stack
 * */

int	biggest_num(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*head;
	int		max;

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

/*
 * indexing_stack - indexing the stack (proud of this function)
 * @stk: pointer which hold address of the stack
 * */

void	indexing_stack(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*n;
	int		index;

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

/*
 * stack_size - checking for the biggest index on the stack
 * @stk: pointer which hold address of the stack
 * Return: returns the position of the biggest index on the stack
 * */
int	stack_size(t_stack *stk)
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
