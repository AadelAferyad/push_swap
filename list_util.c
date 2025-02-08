/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:03:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/07 23:24:41 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static stack	*ft_alloc(char const *s, int *start, int end, stack **head)
{
	char	*str;
	int		len;
	stack	*node;

	len = end - *start;
	str = ft_substr(s, *start, len);
	if (!str)
		exit(1);
	node = add_node_at_end(head, ft_atoi(str));
	*start = -1;
	free(str);
	return (node);
}

void	ft_collector(stack **head)
{
	stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	head = NULL;
}

static int	ft_split_healper(char const *s, char c, stack **head)
{
	int	i;
	int	j;
	stack	*tmp;
	int	start;

	i = 0;
	j = -1;
	start = -1;
	while (s[++j])
	{
		while (s[j + 1] && s[j] == c)
			j++;
		if (start == -1 && s[j] != c)
			start = j;
		if (s[j + 1] == c || (!s[j + 1] && start != -1))
		{
			tmp = ft_alloc(s, &start, j + 1, head);
			if (!tmp)
			{
				ft_collector(head);
				print_error_and_exit();
			}
		}
	}
	return (0);
}

void	advance_split(char const *s, char c, stack **head)
{

	if (!s)
		return ;
	ft_split_healper(s, c, head);
}
