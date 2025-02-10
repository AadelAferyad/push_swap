/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:29 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:17:39 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * swap_stack - swap two top nodes
 * @stk: double pointer which hold address of the stack (head of list)
 * @str: pointer to the string that will be printed (SA or SB)
 * */

void	swap_stack(t_stack **stk, char *str)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stk;
	if (!head || !head->next)
		return ;
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	*stk = tmp;
	ft_puts(str);
}

/*
 * push_stack - push top node (head) to another stack (stack_b) 
 * @stack_a: double pointer which hold address of the stack a
 * 	(node will pushed from this stack)
 * @stack_b: double pointer which hold address of the stack b
 * 	(node from stack a will be push to this stack)
 * @str: pointer to the string that will be printed (PA or PB)
 * */

void	push_stack(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	if (!(*stack_b))
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		tmp->next = NULL;
		ft_puts(str);
		return ;
	}
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_puts(str);
}

/*
 * rotate_stack - rotate node from head to the end (tail)
 * @stk: double pointer which hold address of the stack
 * @str: pointer to the string that will be printed (RA or RB)
 * */

void	rotate_stack(t_stack **stk, char *str)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stk;
	if (!head || !head->next)
		return ;
	tmp = (*stk)->next;
	while (head->next)
		head = head->next;
	head->next = *stk;
	(*stk)->next = NULL;
	*stk = tmp;
	if (str)
		ft_puts(str);
}

/*
 * reverse_rotate_stack - reverse rotate node from end (tail) to top (head)
 * @stk: double pointer which hold address of the stack
 * @str: pointer to the string that will be printed (RRA or RRB)
 * */

void	reverse_rotate_stack(t_stack **stk, char *str)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stk;
	if (!head || !head->next)
		return ;
	while (head->next)
	{
		if (!head->next->next)
			tmp = head;
		head = head->next;
	}
	head->next = *stk;
	tmp->next = NULL;
	*stk = head;
	if (str)
		ft_puts(str);
}
