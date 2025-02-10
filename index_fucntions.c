/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_fucntions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:09:32 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 15:04:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * max_index - searching for the biggest index on the stack
 * @stk: pointer to the stack
 * Return: returns the biggest index
 * */
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

/*
 * lowest_index - searching for the lowest index on the stack
 * @stk: pointer to the stack
 * Return: returns the lowest index
 * */

int	lowest_index(stack *stk)
{
	int	tmp;

	tmp = stk->index;
	while (stk)
	{
		if (stk->index < tmp)
			tmp = stk->index;
		stk = stk->next;
	}
	return (tmp);
}

/*
 * is_big - check if the index is the biggest in stack
 * @stk: pointer to the stack
 * @index: current index
 * Return: returns 0 if false otherwise 1
 * */

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

/*
 * is_small - check if the index is the smallest in stack
 * @stk: pointer to the stack
 * @index: current index
 * Return: returns 0 if false otherwise 1
 * */

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
