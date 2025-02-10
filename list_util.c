/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:03:28 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 14:57:45 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * ft_alloc - allocate node
 * @s: pointer to the string
 * start: pointer to int start of the word
 * end: integer position of the end of the word
 * @head: double pointer holde pointer to the stack
 * Return: returns the created node otherwise NULL
 * */

static stack	*ft_alloc(char *s, int *start, int end, stack **head)
{
	char	*str;
	stack	*node;
	int		len;
	int		overflow;

	overflow = 0;
	len = end - *start;
	str = ft_substr(s, *start, len);
	if (!str)
		exit(1);
	node = add_node_at_end(head, improved_atoi(str, &overflow));
	*start = -1;
	free(str);
	if (overflow == 1)
		return (NULL);
	return (node);
}

/*
 * ft_collector - free all the node in the stack
 * @head: double pointer holde pointer to the stack
 * */

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

/*
 * ft_split_healper - fucntion helper seach for the start/end of substring
 * @s: pointer to the string
 * @c: the characted, string will be splitted by
 * @head: double pointer holde pointer to the stack
 * */

static int	ft_split_healper(char *s, char c, stack **head)
{
	stack	*tmp;
	int		i;
	int		j;
	int		start;

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
				print_error_free_exit(head);
		}
	}
	return (0);
}

/*
 * advance_split - split a sting with space and convert then to data
 * 	for the stack
 * @s: pointer to the string
 * @c: the characted, string will be splitted by
 * @head: double pointer holde pointer to the stack
 * */

void	advance_split(char *s, char c, stack **head)
{
	if (!s)
		return ;
	ft_split_healper(s, c, head);
}
