/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/16 15:54:23 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

stack	*add_node_at_end(stack **head, int data)
{
	stack	*node;
	stack	*tmp;

	tmp = *head;
	node = ft_calloc(sizeof(stack), 1);
	if (!node)
		return (NULL);
	node->data = data;
	if (!tmp)
	{
		*head = node;
		return (node);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
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
		temp = add_node_at_end(&head, ft_atoi(av[i]));
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

	stack_a = create_stack(ac, av);
	while (stack_a)
	{
		printf("<-- %d -->", stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}
