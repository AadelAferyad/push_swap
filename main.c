/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 00:32:13 by aaferyad         ###   ########.fr       */
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
		printf("[%d (%d)]--> ", stk->data, stk->index);
		stk = stk->next;
	}
	printf("\n");
}


/*
 * [3] 9 4 1 2 5
 *
 * */

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
	int	size_1;
	int	size_2;

	stack_b = NULL;
	stack_a = parser(ac, av);
	indexing_stack(stack_a);
	size_1 = stack_size(stack_a);
	if (stack_a)
		sort_stack(&stack_a, &stack_b);
	size_2 = stack_size(stack_a);
	/*print_stack(stack_a);*/
	/*if (size_1 == size_2 && !is_sorted(stack_a))*/
	/*	printf("True it's sorted \n");*/
	/*else*/
	/*	printf("False it's not sorted \n");*/
	ft_collector(&stack_a);
	ft_collector(&stack_b);
	return (0);
}
