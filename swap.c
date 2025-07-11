/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:24:54 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/05 10:24:54 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_node **stack_a)
{
	t_node	*temp;
	t_node	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	tmp = temp->next;
	temp->next = tmp->next;
	tmp->next = temp;
	*stack_a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	tmp = temp->next;
	temp->next = tmp->next;
	tmp->next = temp;
	*stack_b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

/*int main(void)
{
    t_node *stack_a = NULL;
    t_node *tmp;

    append_node(&stack_a, new_node(1));
    append_node(&stack_a, new_node(2));
    append_node(&stack_a, new_node(3));
    append_node(&stack_a, new_node(4));
    printf("Before sa: ");
    tmp = stack_a;
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    sa(&stack_a);
    printf("After sa: ");
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