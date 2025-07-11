/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:10:57 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/06 09:10:57 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void  sort_two(t_node **stack_a)
{
  if (!*stack_a || !(*stack_a)->next)
		return ;
  if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void  sort_three(t_node **stack_a)
{
  int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	pos;

	min = find_min(*stack_a);
	pos = find_pos(*stack_a, min);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	pos;

	min = find_min(*stack_a);
	pos = find_pos(*stack_a, min);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	min = find_min(*stack_a);
	pos = find_pos(*stack_a, min);
	move_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*int main()
{
  t_node *stack_a =NULL;
  t_node *temp;
  t_node *stack_b=NULL;
  append_node(&stack_a,new_node(9));
  append_node(&stack_a,new_node(7));
  append_node(&stack_a,new_node(4));
  append_node(&stack_a,new_node(5));
  append_node(&stack_a,new_node(2));
  printf("before sorting :");
  temp =stack_a;
  while(temp)
  {
    printf("%d ",temp->value);
    temp=temp->next;
  }
  printf("\n");
  sort_five(&stack_a,&stack_b);
  printf("after sorting :");
  temp =stack_a;
  while(temp)
  {
    printf("%d ",temp->value);
    temp=temp->next;
  }
  printf("\n");
  free_list(stack_a);
}*/