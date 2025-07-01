/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:42:50 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/01 15:17:38 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_size(t_node *head)
{
	t_node	*temp;
	int		count;

	count = 0;
	temp = head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	copy_to_array(t_node *head, int *arr)
{
	int	i;

	i = 0;
	while (head)
	{
		arr[i] = head->value;
		i++;
		head = head->next;
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_node *head)
{
	int		size;
	int		*arr;
	t_node	*node;

	size = list_size(head);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit_error();
	copy_to_array(head, arr);
	sort_array(arr, size);
	node = head;
	while (node)
	{
		node->value = find_index(arr, size, node->value);
		node = node->next;
	}
	free(arr);
}
