/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:13:37 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * sort_two - sort two number on the stack if stack size is 2
 * @stk: double pointer which holde pointer to the stack
 * */

static void	sort_two(t_stack **stk)
{
	t_stack	*tmp;
	int		size;

	size = stack_size(*stk);
	if (size == 1)
		return ;
	tmp = *stk;
	if (tmp->index > tmp->next->index)
		swap_stack(stk, SA);
}
/*
 * main - Entry point
 *
 * @ac: the argument count.
 * @av: the argument vector.
 *
 * Return: Always 0 (Success).
 */

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
