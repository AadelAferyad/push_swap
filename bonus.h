/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:32 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 23:29:21 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "main.h"
# include "gnl/get_next_line.h"

int		strcmpr(char *s1, char *s2);
void	assign(char **ptr);
int		check_which_op(char *str);
int		eval(t_stack **stack_a, t_stack **stack_b, char *str);
int		is_op_valid(char *str);
int		check_str(char *str);
#endif
