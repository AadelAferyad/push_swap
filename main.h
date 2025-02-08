/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:50:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/07 23:24:39 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_FT
#define MAIN_FT

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#define SA "sa\n"
#define SB "sb\n"

#define SS "ss\n"

#define PA "pa\n"
#define PB "pb\n"

#define RA "ra\n"
#define RB "rb\n"

#define RR "rr\n"

#define RRA "rra\n"
#define RRB "rrb\n"

#define RRR "rrr\n"

typedef struct stack_list
{
	int	data;
	int	index;
	int	op;
	int	target;
	struct stack_list	*next;
} stack;


void	swap_stack(stack **stk, char *str);
void	find_head(stack **stk);
void	push_stack(stack **stack_a, stack **stack_b, char *str);
void	rotate_stack(stack **stk, char *str);
void	reverse_rotate_stack(stack **stk, char *str);
void	rotate_both_stack(stack **stack_a, stack **stack_b);

int	stack_size(stack *stk);
void	sort_stack(stack **stack_a, stack **stack_b);
void	print_stack(stack *stk);
void	unset_operation(stack *stk);
void	reverse_rotate_both_stack(stack **stack_a, stack **stack_b);

void	advance_split(char const *s, char c, stack **head);

stack	*parser(int ac, char **av);
void	ft_collector(stack **head);
void	print_error_and_exit();

stack	*add_node_at_end(stack **head, int data);
#endif 
