/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:05:49 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/07 23:40:59 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
int	checker_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	checker_is_dup(stack *head)
{
	stack	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (tmp->data == head->data)
				print_error_and_exit();
			tmp = tmp->next;
		}
		head = head->next;
	}

}

void	checker_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			print_error_and_exit();
		else if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			print_error_and_exit();
		i++;
	}
}

stack	*parser(int ac, char **av)
{
	int	i;
	stack	*head;

	head = NULL;
	i = 1;
	if (ac == 1)
		exit(0);
	while (i < ac)
	{
		checker_is_digit(av[i]);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		advance_split(av[i], ' ' , &head);
		i++;
	}
	checker_is_dup(head);
	return (head);
}

