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


void	swap_stack(stack **stk, char *str)
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
	ft_puts(str);
}

void	push_stack(stack **stack_a, stack **stack_b, char *str)
{
	stack	*tmp;

	if (!(*stack_b))
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		tmp->next = NULL;
		ft_puts(str);
		return ;
	}
	if (!(*stack_b) || !(*stack_a))
		return ;

	tmp = *stack_a;

	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;

	tmp->next = *stack_b;
	tmp->prev = NULL;

	*stack_b = tmp;
	ft_puts(str);
}

void	rotate_stack(stack **stk, char *str)
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
	ft_puts(str);	
}


void	reverse_rotate_stack(stack **stk, char *str)
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
	ft_puts(str);	

}

