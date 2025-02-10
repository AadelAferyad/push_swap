/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:37:08 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 15:07:48 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * ft_check_escape - check if a string contain any sort of space
 * @s: pointer to char holds the string
 * @c: character we locking for
 * Return: returns 0 if space found otherwise 1 
 */

static int	ft_check_escape(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

/*
 * improved_atoi - ascii to intger
 * @nptr: pointer to char
 * @overflow: pointer to int (flag for overflow scenario)
 * Return: integer
 */

int	improved_atoi(char *nptr, int *overflow)
{
	long	n;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	n = 0;
	while (!ft_check_escape(" \n\t\v\f\r", nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (nptr[i] - '0') + n * 10;
		i++;
	}
	n = n * sign;
	if (n > MAX_INT || n < MIN_INT)
		*overflow = 1;
	return ((int)(n));
}
