/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:22:25 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/08 09:22:25 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int find_max_index(t_node *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void radix_sort(t_node **stack_a, t_node **stack_b)
{
	int max_num;
	int max_bits;
	int i;
	int j;
	int size;

	size = list_size(*stack_a);
	max_num = find_max_index(*stack_a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->value >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
