/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:23:33 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 00:31:53 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	adjust_push(stack **stack_a, stack **stack_b)
{
	stack	*tmp;
	int	op_a;
	int	op_b;
	int	i;

	i = 0;
	tmp = *stack_a;
	while (!tmp->op)
		tmp = tmp->next;
	/*printf("%d %d\n", tmp->index, tmp->op);*/
	/*printf("called \n");*/
	op_a = index_of_node(*stack_a, tmp->index);
	op_b = stack_b_operations(*stack_b, tmp->index);
	while (i < tmp->op - 1)
	{
		if (op_a > 0 && op_b > 0)
		{
			op_a--;
			op_b--;
			rotate_both_stack(stack_a, stack_b);
		}
		else if (op_a < 0 && op_b < 0)
		{
			op_a++;
			op_b++;
			reverse_rotate_both_stack(stack_a, stack_b);
		}
		else if (op_a > 0)
		{
			rotate_stack(stack_a, RA);
			op_a--;
		}
		else if (op_a < 0)
		{
			reverse_rotate_stack(stack_a, RRA);
			op_a++;
		}
		else if (op_b > 0)
		{
			op_b--;
			rotate_stack(stack_b, RB);
		}
		else if (op_b < 0)
		{
			op_b++;
			reverse_rotate_stack(stack_b, RRB);
		}
	   i++;
	}
	push_stack(stack_a, stack_b, PB);
}
