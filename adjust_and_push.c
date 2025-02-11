/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:23:33 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/11 15:23:03 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * locating_op - locating the cheapest move on stack a
 * @s_b: stack b
 * @s_a: stack a
 * @op_a: pointer for number of op in stack a
 * @op_b: pointer for number of op in stack b
 * */

static t_stack	*locating_op(t_stack *s_a, t_stack *s_b, int *op_a, int *op_b)
{
	t_stack	*tmp;

	tmp = s_a;
	while (!tmp->op)
		tmp = tmp->next;
	*op_a = index_of_node(s_a, tmp->index);
	*op_b = stack_b_operations(s_b, tmp->index);
	return (tmp);
}

/*
 * adjust_helper - function helper rotatet or reverse rotate both stack
 * @a: pointer for number of op in stack a
 * @b: pointer for number of op in stack b
 * @sb: stack b
 * @sa: stack a
 * */

static void	adjust_helper(int *a, int *b, t_stack **sb, t_stack **sa)
{
	if (*a > 0 && *b > 0)
	{
		*a = *a - 1;
		*b = *b - 1;
		rotate_both_stack(sa, sb, RR);
	}
	else if (*a < 0 && *b < 0)
	{
		*a = *a + 1;
		*b = *b + 1;
		reverse_rotate_both_stack(sa, sb, RRR);
	}
}

/*
 * adjust_helper_two - function helper rotatet or reverse rotate stack
 * 	based on the flag
 * @stk: double pointer hold pointer to the stack
 * @op: pointer for number of op
 * @flag: the flag variable it can be 1 or -1
 * @str: message to pass to rotates functions
 * */

static void	adjust_helper_two(t_stack **stk, int *op, int flag, char *str)
{
	if (flag == -1)
	{
		rotate_stack(stk, str);
		*op = *op - 1;
	}
	else if (flag == 1)
	{
		reverse_rotate_stack(stk, str);
		*op = *op + 1;
	}
}

/*
 * adjust_push - pushing the cheapest move to stack b
 * @stack_a: double pointer hold pointer to the stack A
 * @stack_b: double pointer hold pointer to the stack b
 * */

void	adjust_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		op_a;
	int		op_b;
	int		i;

	i = 0;
	tmp = locating_op(*stack_a, *stack_b, &op_a, &op_b);
	while (i < tmp->op - 1)
	{
		if (op_a > 0 && op_b > 0)
			adjust_helper(&op_a, &op_b, stack_b, stack_a);
		else if (op_a < 0 && op_b < 0)
			adjust_helper(&op_a, &op_b, stack_b, stack_a);
		else if (op_a > 0)
			adjust_helper_two(stack_a, &op_a, -1, RA);
		else if (op_a < 0)
			adjust_helper_two(stack_a, &op_a, 1, RRA);
		else if (op_b > 0)
			adjust_helper_two(stack_b, &op_b, -1, RB);
		else if (op_b < 0)
			adjust_helper_two(stack_b, &op_b, 1, RRB);
		i++;
	}
	push_stack(stack_a, stack_b, PB);
}
