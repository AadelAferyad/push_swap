/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 11:23:48 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	unset_operation(stack *stk)
{
	if (!stk)
		return ;
	while (stk)
	{
		stk->op = 0;
		stk = stk->next;
	}
}

void	print_stack(stack *stk)
{
	while (stk)
	{
		printf("[%d (%d)]--> ", stk->data, stk->index);
		stk = stk->next;
	}
	printf("\n");
}


static void	sort_two(stack **stk)
{
	int	size;
	stack	*tmp;

	size = stack_size(*stk);
	if (size == 1)
		return ;
	tmp = *stk;
	if (tmp->index > tmp->next->index)
		swap_stack(stk, SA);
}

int	main(int ac, char **av)
{
	stack	*stack_a;
	stack	*stack_b;

	stack_b = NULL;
	stack_a = parser(ac, av);
	indexing_stack(stack_a);
	if (stack_size(stack_a) < 3)
		sort_two(&stack_a);
	else
		sort_stack(&stack_a, &stack_b);
	ft_collector(&stack_a);
	ft_collector(&stack_b);
	return (0);
}
