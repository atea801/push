/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:23:18 by aautret           #+#    #+#             */
/*   Updated: 2025/08/11 10:56:08 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc / free
# include <unistd.h>
# include <stdio.h>
# include <limits.h> //INT_MAX INT_MIN

# include "ft_printf.h"
# include "libft.h"



typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stack;




// ----------------------------------------------------
// OPERATIONS
// ----------------------------------------------------

void	print_stack(const char *label, t_node *head);
void	push_node(t_node **head, int nb);
int		pop_node(t_node **head);
void	reverse_rotate(t_node **head);
void	rotate(t_node **head);
void	swap(t_node **head);
// WRAPPERS
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);


// ----------------------------------------------------
// PARSING
// ----------------------------------------------------

char	**parsing_split_args(int ac, char **av);
int		parsing_is_valid_number(char *nbr);
int		parsing_has_int_overflow(char *str);
int		parsing_validate_numbers(char **args);
void	clean_free_split(char **str);
int		parsing_check_duplicates(char **args);
t_node	*parsing_build_stack_a(char **args);
void	clean_free_stack(t_node *stack);
t_node	*parsing(int ac, char **av);


// ----------------------------------------------------
// SORTING
// ----------------------------------------------------

void	init_sort(t_node **a);

// INITIALISATION
t_node	*new_node(int value);
int		is_sorted(t_node *a);
int		stack_size(t_node *a);
void	init_sort(t_node **a);

// SMALL SORT
void	sort_2(t_node **a);
void	sort_3(t_node **a);
int		find_min_position(t_node *a);
void	rotate_min_to_top(t_node **a, int pos);
void	reverse_min_to_top(t_node **a, int pos, int size);
void	push_min_until_three(t_node **a, t_node **b);
void	sort_small(t_node **a, t_node **b);

// BIG SORT
void	k_sort(t_node **a, t_node **b);

// BIG SORT > INDEX
void	sort_int_array(int *arr, int size);
void	compress_indices(t_node *a);
// BIG SORT > CHUNKS
int		get_chunk_size(int total_size);
void	push_current_to_b(t_node **a, t_node **b, int value, int limit);
void	push_chunks_to_b(t_node **a, t_node **b, int total_size);
int		find_max_position(t_node *b);
void	rotate_max_to_top(t_node **b, int pos);
void	reverse_max_to_top(t_node **b, int pos, int size);
void	push_back_to_a(t_node **a, t_node **b);
void	rotate_min_to_top(t_node **a, int pos);




// int		build_stack_from_args(t_node **a, char **av);
// void	ksort_push_chunks(t_node **a, t_node **b, int k);
// void	ksort_return_from_b(t_node **a, t_node **b);
// int		choose_k(int len);
int		stack_size(t_node *a);
int		is_sorted(t_node *a);

#endif
