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
void	exit_error(void);
void	check_overflow(long result, int sign);
void	append_node(t_node **head, t_node *node);
void	check_duplicates(t_node *head);
void	parse_input(int argc, char **argv, t_node *stack_a);
void	copy_to_array(t_node *head, int *arr);
void	sort_array(int *arr, int size);
void	index_stack(t_node *head);
char	**ft_split(char const *s, char c);

#endif