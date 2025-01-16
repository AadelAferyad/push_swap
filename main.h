/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:50:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/16 15:46:21 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_FT
#define MAIN_FT

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct stack_list
{
	int	data;
	struct stack_list	*perv;
	struct stack_list	*next;
} stack;

#endif 
