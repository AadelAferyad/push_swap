/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:23:04 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 11:26:14 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * rotate_both_stack - rotate node from head to the end for both stack
 * @stack_a: double pointer which hold address of the stack a
 * @stack_b: double pointer which hold address of the stack b
 * */

void	rotate_both_stack(stack **stack_a, stack **stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	ft_puts("rr\n");
}

/*
 * revesre_rotate_both_stack - rotate node from end to the beginning
 *	 for both stack
 * @stack_a: double pointer which hold address of the stack a
 * @stack_b: double pointer which hold address of the stack b
 * */

void	reverse_rotate_both_stack(stack **stack_a, stack **stack_b)
{
	reverse_rotate_stack(stack_a, NULL);
	reverse_rotate_stack(stack_b, NULL);
	ft_puts("rrr\n");
}

/*
 * add_node_at_end - create new node and add it to the end of list
 * @head: double pointer which hold address of the list
 * @data: integer variable holds the data
 * Return: returns the created node or NULL if failed
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
