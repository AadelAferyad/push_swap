/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/17 13:05:06 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	find_head(stack **stk)
{
	while ((*stk)->prev)
		(*stk) = (*stk)->prev;
}


stack	*add_node_at_begining(stack **head, int data)
{
	stack	*node;

	node = ft_calloc(sizeof(stack), 1);
	if (!node)
		return (NULL);
	node->data = data;
	if (!(*head))
	{
		*head = node;
		return (node);
	}
	node->next = *head;
	(*head)->prev = node;
	*head = node;
	return (node);
}

stack	*create_stack(int ac, char **av)
{
	stack	*head;
	stack	*temp;
	int	i;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		temp = add_node_at_begining(&head, ft_atoi(av[i]));
		if (!temp)
		{
			while (head)
			{
				temp = head->next;
				free(head);
				head = temp;
			}
			return (NULL);
		}
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;

	stack_a = create_stack(ac, av);
	while (stack_a)
	{
		printf("<-- %d -->", stack_a->data);
		if (!stack_a->next)
			break;
		stack_a = stack_a->next;
	}
	find_head(&stack_a);
	printf("\n");
	reverse_rotate_stack(&stack_a);
	while (stack_a)
	{
		printf("<-- %d -->", stack_a->data);
		if (!stack_a->next)
			break;
		stack_a = stack_a->next;
	}
	return (0);
}
