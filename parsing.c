/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:43:12 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/01 13:36:59 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof (t_node));
	if (!new)
		exit_error();
	new->value = value;
	new->next = NULL;
	return (new);
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	append_node(t_node **head, t_node *node)
{
	t_node	*temp;

	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

void	check_duplicates(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				exit_error();
			temp = temp->next;
		}
		current = current->next;
	}
}

void	parse_input(int argc, char **argv, t_node **stack_a)
{
	int		i;
	char	**temp;
	int		value;
	int		j;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			exit_error();
		j = 0;
		while (temp[j])
		{
			value = ft_atoi(temp[j]);
			node = new_node(value);
			append_node(stack_a, node);
			free(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	check_duplicates(*stack_a);
}
