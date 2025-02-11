/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:37:24 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/11 17:44:23 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	strcmpr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	assign(char **ptr)
{
	ptr[0] = "sa";
	ptr[1] = "sb";
	ptr[2] = "ss";
	ptr[3] = "ra";
	ptr[4] = "rb";
	ptr[5] = "rr";
	ptr[6] = "rra";
	ptr[7] = "rrb";
	ptr[8] = "rrr";
	ptr[9] = "pa";
	ptr[10] = "pb";
	ptr[11] = NULL;
}

int	check_which_op(char *str)
{
	char	*op[12];
	int		i;

	i = 0;
	if (!str || *str == '\0')
		return (-1);
	assign(op);
	while (op[i])
	{
		if (!strcmpr(str, op[i]))
			return (i);
		i++;
	}
	return (-1);
}

static void	eval_helper(int i, t_stack **stack_a, t_stack **stack_b)
{
	if (i == 0)
		swap_stack(stack_a, NULL);
	if (i == 1)
		swap_stack(stack_b, NULL);
	if (i == 2)
		swap_both_stack(stack_a, stack_b, NULL);
	if (i == 3)
		rotate_stack(stack_a, NULL);
	if (i == 4)
		rotate_stack(stack_b, NULL);
	if (i == 5)
		rotate_both_stack(stack_a, stack_b, NULL);
	if (i == 6)
		reverse_rotate_stack(stack_a, NULL);
	if (i == 7)
		reverse_rotate_stack(stack_b, NULL);
	if (i == 8)
		reverse_rotate_both_stack(stack_a, stack_b, NULL);
	if (i == 9)
		push_stack(stack_b, stack_a, NULL);
	if (i == 10)
		push_stack(stack_a, stack_b, NULL);
}

int	eval(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	i;

	i = check_which_op(str);
	if (i == -1)
		return (1);
	eval_helper(i, stack_a, stack_b);
	return (0);
}
