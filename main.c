/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/07 23:25:04 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	unset_operation(stack *stk)
{
	if (!stk)
		return ;
	while (stk)
	{
		stk->op = 0;
		stk = stk->next;
	}
}
void	print_stack(stack *stk)
{
	while (stk)
	{
		printf("%d ", stk->data);
		stk = stk->next;
	}
	printf("\n");
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

/*
 * [3] 9 4 1 2 5
 *
 * */
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

stack	*add_node_at_end(stack **head, int data)
{
	stack	*node;
	stack	*tmp;

	tmp = *head;
	node = malloc(sizeof(stack) * 1);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->data = data;
	if (!(*head))
	{
		*head = node;
		return (node);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (node);
}


int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;

	stack_b = NULL;
	stack_a = parser(ac, av);
	indexing_stack(stack_a);
	if (stack_a)
		sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	ft_collector(&stack_a);
	return (0);
}
