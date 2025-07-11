/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:18:20 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/05 09:18:20 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

/*int main(void)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    append_node(&stack_a, new_node(1));
    append_node(&stack_a, new_node(2));
    append_node(&stack_a, new_node(3));
    append_node(&stack_b, new_node(4));
    append_node(&stack_b, new_node(5));
    pa(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    free_list(stack_a);
    free_list(stack_b);
    return 0;
}*/
