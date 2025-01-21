/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:30:27 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/17 13:04:50 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_stack(stack **stk)
{
	stack	*head;
	stack	*tmp;

	head = *stk;
	if (!head || !head->next)
		return ;
	tmp = head->next;
	head->next = head->next->next;
	head->prev = tmp;
	tmp->next = head;
	tmp->prev = NULL;
	*stk = tmp;
}

void	push_stack(stack **stack_a, stack **stack_b)
{
	stack	*tmp;
	stack	*head;

	if (!(*stack_b))
		return ;

	head = *stack_b;
	tmp = head->next;

	head->next = *stack_a;
	head->prev = NULL;
	*stack_b = tmp;
	if (!(*stack_a))
	{
		*stack_a = head;
		return ;
	}
	(*stack_a)->prev = head;
	*stack_a = head;
}

void	rotate_stack(stack **stk)
{
	stack	*tmp;
	stack	*head;

	head = *stk;
	tmp = (*stk)->next;
	if (!head || !head->next)
		return ;
	while (head->next)
		head = head->next;

	head->next = *stk;
	(*stk)->prev = head;
	(*stk)->next = NULL;
	
	tmp->prev = NULL;
	*stk = tmp;
}


void	reverse_rotate_stack(stack **stk)
{
	stack	*head;
	stack	*tmp;
	stack	*prev;

	head = *stk;

	while (head->next)
		head = head->next;

	prev = head->prev;
	prev->next = NULL;

	head->prev = NULL;
	head->next = *stk;

	(*stk)->prev = head;
	*stk = head;
}

