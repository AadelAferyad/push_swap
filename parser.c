/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:05:49 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 14:04:21 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * checker_is_space - cheking if the string contain a space
 * @str: pointer to str that will be checked
 * Return: returns 1 if space found otherwise 0
 * */

static int	checker_is_space(char *str)
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

/*
 * checker_is_dup - check if the numbers are duplicated
 * 	if duplicated it frees the stack and print error and exits
 * @head: double pointer to the head of the stack
 * */

static void	checker_is_dup(stack **head)
{
	stack	*tmp;
	stack	*ptr;

	ptr = *head;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (tmp->data == ptr->data)
				print_error_free_exit(head);
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

/*
 * checker_is_digit - check if argument is digit if not 
 * 	it print error and exits 
 * @str: pointer to string with contain argumets or at least one
 * */

static void	checker_is_digit(char *str)
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

/*
 * parser - parse the argumets passed by argv and check them
 * @ac: argument count number of argument passed to the programe
 * @av: argument vector it contains pointer to char holding arguments
 * Return: if arguments are valid it create stack and returns it
 * 	otherwise it print error and exit
 * */

stack	*parser(int ac, char **av)
{
	stack	*head;
	int		i;

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
		advance_split(av[i], ' ', &head);
		i++;
	}
	checker_is_dup(&head);
	return (head);
}
