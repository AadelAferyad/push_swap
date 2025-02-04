/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:30:27 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/27 11:34:53 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	swap_stack(stack **stk, char *str)
{
	stack	*head;
	stack	*tmp;

	head = *stk;
/*
 * stk =  N<--(0)-->(1)-->N;
 * head = (0)
 * tmp = (1);
 * head->next = (1)<--(0)-->N
 * tmp : N<--(1)-->(9);
 * stk = 1
 * */
	if (!head || !head->next)
		return ;
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	*stk = tmp;
	ft_puts(str);
}

void	push_stack(stack **stack_a, stack **stack_b, char *str)
{
	stack	*tmp;

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

void	rotate_stack(stack **stk, char *str)
{
	stack	*tmp;
	stack	*head;

	head = *stk;
	if (!head || !head->next)
		return ;
	tmp = (*stk)->next;
	while (head->next)
		head = head->next;
	/*if (tmp == head)*/
	/*	swap_stack(stk, str);*/
	head->next = *stk;
	(*stk)->next = NULL;
	
	*stk = tmp;
	if (str)
		ft_puts(str);	
}

void	reverse_rotate_stack(stack **stk, char *str)
{
	stack	*head;
	stack	*tmp;

	head = *stk;

	if (!head || !head->next)
		return ;
	while (head->next)
	{
		if (!head->next->next)
			tmp = head;
		head = head->next;
	}
	/*printf("head : %d\n", head->data);*/

	head->next = *stk;
	tmp->next = NULL;

	*stk = head;
	if (str)
		ft_puts(str);
	/*print_stack(*stk);*/
}

void	rotate_both_stack(stack **stack_a, stack **stack_b)
{
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	ft_puts("rr\n");
}

void	reverse_rotate_both_stack(stack **stack_a, stack **stack_b)
{
	reverse_rotate_stack(stack_a, NULL);
	reverse_rotate_stack(stack_b, NULL);
	ft_puts("rrr\n");
}
