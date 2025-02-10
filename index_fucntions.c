/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_fucntions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:09:32 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 00:32:01 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	small_index(stack *stk)
{
	int	i;

	i = stk->index;
	while (stk)
	{
		if (i > stk->index)
			i = stk->index;
		stk = stk->next;
	}
	return (i);
}

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
