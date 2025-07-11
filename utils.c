/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:40:12 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/11 12:07:57 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_pos(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	move_to_top(t_node **stack, int pos)
{
	int	size;

	size = list_size(*stack);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(stack);
	}
}
