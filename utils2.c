/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:20:39 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/11 13:22:43 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	exit_error_with_cleanup(t_node **stack_a, char **split_array, int *arr)
{
	int	i;

	if (stack_a && *stack_a)
		free_list(*stack_a);
	if (split_array)
	{
		i = 0;
		while (split_array[i])
		{
			free(split_array[i]);
			i++;
		}
		free(split_array);
	}
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX)
		|| (sign == -1 && - result < INT_MIN))
		exit_error();
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
