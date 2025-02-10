/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:37:08 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 10:48:40 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int	improved_atoi(char *nptr, int *overflow)
{
	long	n;
	int	sign;
	int	i;

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
