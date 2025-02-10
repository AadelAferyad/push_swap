/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:50:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 10:48:18 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_FT
#define MAIN_FT

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

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


int	small_index(stack *stk);
int	max_index(stack *stk);
int	lowest_index(stack *stk);
int	is_big(stack *stk, int index);
int	is_small(stack *stk, int index);
int	index_of_node(stack *stk, int index);
int	is_big_or_small(stack *stk, int index);
int	biggest_num(stack *stk);
void	indexing_stack(stack *stk);

int	find_right_position(stack *stk, int index, int big_or_small);
int	stack_b_operations(stack *stack_b, int index);
int	closest_operation(stack *stack_a, stack *stack_b, int index);
void	set_operations(stack *stack_a, stack *stack_b);
void	find_best_op(stack *stack_a, stack *stack_b);
void	adjust_push(stack **stack_a, stack **stack_b);

int	improved_atoi(char *nptr, int *overflow);
void	print_error_free_exit(stack **stk);
#endif 
