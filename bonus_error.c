/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:24:41 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 23:30:08 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_op_valid(char *str)
{
	char	tmp;
	int		i;
	int		len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	tmp = str[len - 1];
	str[len - 1] = '\0';
	i = check_which_op(str);
	str[len - 1] = tmp;
	return (i);
}

int	check_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (*str != '\0' && (*str == '\n' && str[1] == '\0'))
	{
		free(str);
		return (1);
	}
	while (str[i])
	{
		if (str[i] == '\n')
			flag++;
		if (str[i] != '\n' && flag)
			flag = 0;
		if (flag > 1)
		{
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}
