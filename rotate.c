/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:59:23 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/05 10:59:23 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
  write(1, "ra\n", 3);
}

void  rb(t_node **stack_b)
{
  t_node	*temp;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
  write(1, "rb\n", 3);
}

void	rr(t_node **stack_a,t_node **stack_b)
{
  ra(stack_a);
  rb(stack_b);
  write(1, "rr\n", 3);
}

/*int main(void)
{
  t_node *stack_a = NULL;
  t_node *tmp;
  append_node(&stack_a, new_node(1));
  append_node(&stack_a, new_node(2));
  append_node(&stack_a, new_node(3));
  append_node(&stack_a, new_node(4));
  printf("Before ra: ");
  tmp = stack_a;
  while (tmp)
  {
     printf("%d ", tmp->value);
     tmp = tmp->next;
  }
  printf("\n");
  ra(&stack_a);
  printf("After ra: ");
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