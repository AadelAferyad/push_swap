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
	head->next = head->next->next;
	head->prev = tmp;
	tmp->next = head;
	tmp->prev = NULL;
	*stk = tmp;
	ft_puts(str);
}

void	push_stack(stack **stack_a, stack **stack_b, char *str)
{
	stack	*tmp;
/*
 * a : N<--(99)-->(2)-->N
 * b : 
 * tmp = (99)
 * a = N<--(2)-->N
 * b : (99)-->N
 * */
	if (!(*stack_a))
		return ;
	if (!(*stack_b))
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		*stack_b = tmp;
		tmp->next = NULL;
		ft_puts(str);
		return ;
	}
/*
 * a : N<--(19)-->(2)-->N
 * b : N<--(99)-->N
 * tmp = (19)
 * a = N<--(2)-->N
 * tmp = N<--(19)-->(99)
 * b : (99)-->N
 * */
	tmp = *stack_a;

	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;

	tmp->next = *stack_b;
	tmp->prev = NULL;

	(*stack_b)->prev = tmp;
	*stack_b = tmp;
	ft_puts(str);
}

void	rotate_stack(stack **stk, char *str)
{
	stack	*tmp;
	stack	*head;

/*
 * stk : N<--(19)-->(2)-->(3)-->N
 * head = (19)
 * tmp = (2)
 * head = (3);
 * head->next = (3)-->19;
 * stk = 3<--(19)-->N
 * tmp : N<--(2)
 * stk = N<--(2)-->(3)-->(19)-->N
 * */
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
	if (str)
		ft_puts(str);	
}

void	reverse_rotate_stack(stack **stk, char *str)
{
	stack	*head;
	stack	*tmp;
	stack	*prev;

	head = *stk;

	if (!head || !head->next)
		return ;
	while (head->next)
		head = head->next;
/*
 *stk =  N<--(0)-->(1)-->N;
 * prev = 1<--0-->N
 * head = N<--1-->0;
 * stk = 1<--0
 * stk = N<--1-->0
 * */
	prev = head->prev;
	prev->next = NULL;

	if (prev == *stk)
		prev->prev = head;
	head->prev = NULL;
	head->next = *stk;

	(*stk)->prev = head;
	*stk = head;
	if (str)
		ft_puts(str);
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
