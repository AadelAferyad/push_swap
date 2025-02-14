/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:41:15 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 23:29:42 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

static void	execute(t_stack **stack_a, t_stack **stack_b, char *str)
{
	char	**grid;
	int		i;

	if (check_str(str))
		print_error_free_exit(stack_a);
	grid = ft_split(str, '\n');
	free(str);
	if (!grid)
		print_error_free_exit(stack_a);
	i = 0;
	while (grid[i])
	{
		if (eval(stack_a, stack_b, grid[i]))
		{
			free_grid(grid);
			ft_collector(stack_a);
			ft_collector(stack_b);
			print_error_and_exit();
		}
		i++;
	}
	free_grid(grid);
}

void	print_results(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_a) && !stack_b)
		ft_puts("OK\n");
	else
		ft_puts("KO\n");
}

char	*read_inputs(t_stack **stack_a)
{
	char	*sub_buffer;
	char	*buffer;

	buffer = NULL;
	sub_buffer = get_next_line(0);
	while (sub_buffer)
	{
		if (sub_buffer && is_op_valid(sub_buffer) == -1)
		{
			free(sub_buffer);
			free(buffer);
			print_error_free_exit(stack_a);
		}
		buffer = ft_strjoin_gnl(buffer, sub_buffer);
		free(sub_buffer);
		sub_buffer = get_next_line(0);
	}
	return (buffer);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*buffer;

	stack_b = NULL;
	stack_a = parser(ac, av);
	indexing_stack(stack_a);
	buffer = read_inputs(&stack_a);
	if (buffer)
		execute(&stack_a, &stack_b, buffer);
	print_results(stack_a, stack_b);
	ft_collector(&stack_a);
	ft_collector(&stack_b);
	return (0);
}
