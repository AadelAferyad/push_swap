/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:45:13 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:16:43 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * print_error_and_exit - print error and exit
 * */

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*
 * print_error_and_exit - print error and free stack then exit
 * */

void	print_error_free_exit(t_stack **stk)
{
	ft_collector(stk);
	print_error_and_exit();
}
