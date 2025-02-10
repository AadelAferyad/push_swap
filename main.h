/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:50:21 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 16:10:40 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define SA "sa\n"
# define SB "sb\n"

# define SS "ss\n"

# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct stack_list
{
	int					data;
	int					index;
	int					op;
	int					target;
	struct stack_list	*next;
}	t_stack;

void		swap_stack(t_stack **stk, char *str);
void		find_head(t_stack **stk);
void		push_stack(t_stack **stack_a, t_stack **stack_b, char *str);
void		rotate_stack(t_stack **stk, char *str);
void		reverse_rotate_stack(t_stack **stk, char *str);
void		rotate_both_stack(t_stack **stack_a, t_stack **stack_b);
int			stack_size(t_stack *stk);
void		sort_stack(t_stack **stack_a, t_stack **stack_b);
void		print_stack(t_stack *stk);
void		unset_operation(t_stack *stk);
void		reverse_rotate_both_stack(t_stack **stack_a, t_stack **stack_b);
void		advance_split(char *s, char c, t_stack **head);
t_stack		*parser(int ac, char **av);
void		ft_collector(t_stack **head);
void		print_error_and_exit(void);
t_stack		*add_node_at_end(t_stack **head, int data);
int			small_index(t_stack *stk);
int			max_index(t_stack *stk);
int			lowest_index(t_stack *stk);
int			is_big(t_stack *stk, int index);
int			is_small(t_stack *stk, int index);
int			index_of_node(t_stack *stk, int index);
int			is_big_or_small(t_stack *stk, int index);
int			biggest_num(t_stack *stk);
void		indexing_stack(t_stack *stk);
int			find_right_position(t_stack *stk, int index, int big_or_small);
int			stack_b_operations(t_stack *stack_b, int index);
int			closest_operation(t_stack *stack_a, t_stack *stack_b, int index);
int			is_sorted(t_stack *stk);
void		set_operations(t_stack *stack_a, t_stack *stack_b);
void		find_best_op(t_stack *stack_a, t_stack *stack_b);
void		adjust_push(t_stack **stack_a, t_stack **stack_b);
int			improved_atoi(char *nptr, int *overflow);
void		print_error_free_exit(t_stack **stk);

#endif 
