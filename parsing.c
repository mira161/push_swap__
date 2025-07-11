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
		return (NULL);
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
			{
				free_list(head);
				exit_error();
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

static void	process_argument(char *arg, t_node **stack_a)
{
	char	**temp;
	int		value;
	int		j;
	t_node	*node;

	temp = ft_split(arg, ' ');
	if (!temp)
		exit_error_with_cleanup(stack_a, NULL, NULL);
	j = 0;
	while (temp[j])
	{
		if (!ft_atoi_safe(temp[j], &value))
			exit_error_with_cleanup(stack_a, temp, NULL);
		node = new_node(value);
		if (!node)
			exit_error_with_cleanup(stack_a, temp, NULL);
		append_node(stack_a, node);
		free(temp[j]);
		j++;
	}
	free(temp);
}

void	parse_input(int argc, char **argv, t_node **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		process_argument(argv[i], stack_a);
		i++;
	}
	check_duplicates(*stack_a);
}
