/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:50:06 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/06 08:50:06 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
    write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
    write(1, "rrb\n", 4);
}

void		rrr(t_node **stack_a,t_node **stack_b)
{
  rra(stack_a);
  rrb(stack_b);
  write(1, "rrr\n", 4);
}

/*int main(void)
{
    t_node *stack_a = NULL;
    t_node *tmp;

    append_node(&stack_a, new_node(1));
    append_node(&stack_a, new_node(2));
    append_node(&stack_a, new_node(3));
    append_node(&stack_a, new_node(4));
    printf("Before rra: ");
    tmp = stack_a;
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    rra(&stack_a);
    printf("After rra: ");
    tmp = stack_a;
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    free_list(stack_a);
    return (0);
}*/