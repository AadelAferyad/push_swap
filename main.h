/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:50:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/01/17 13:00:34 by aaferyad         ###   ########.fr       */
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
	struct stack_list	*prev;
	struct stack_list	*next;
} stack;

void	swap_stack(stack **stk);
void	find_head(stack **stk);
void	push_stack(stack **stack_a, stack **stack_b);
void	rotate_stack(stack **stk);
void	reverse_rotate_stack(stack **stk);
#endif 
