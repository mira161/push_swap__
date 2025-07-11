/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:38:40 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/01 15:06:44 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct n_node
{
	int				value;
	struct n_node	*next;
}	t_node;

int		ft_atoi(const char *nptr);
int		list_size(t_node *head);
int		find_index(int *arr, int size, int value);
int		find_min(t_node *stack);
int		find_pos(t_node *stack, int value);
int		find_max_index(t_node *stack);
int		is_sorted(t_node *stack);
void	exit_error(void);
void	check_overflow(long result, int sign);
void	append_node(t_node **head, t_node *node);
void	check_duplicates(t_node *head);
void	parse_input(int argc, char **argv, t_node **stack_a);
void	copy_to_array(t_node *head, int *arr);
void	sort_array(int *arr, int size);
void	index_stack(t_node *head);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	free_list(t_node *head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	move_to_top(t_node **stack, int pos);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	push_swap(t_node **stack_a, t_node **stack_b);
void 	print_stack(t_node *stack);
char	**ft_split(char const *s, char c);
t_node	*new_node(int value);

#endif
