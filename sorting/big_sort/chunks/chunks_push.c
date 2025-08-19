/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:48:37 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:21:20 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  transfère les éléments de A vers B par groupes (chunks) successifs,
 * selon la taille totale de la pile.
 *
 * @param a
 * @param b
 * @param total_size
 */
void	push_chunks_to_b(t_node **a, t_node **b, int total_size)
{
	int	chunk_size;
	int	limit;

	chunk_size = get_chunk_size(total_size);
	limit = chunk_size;
	while (*a)
	{
		if ((*a)->value <= limit)
		{
			push_current_to_b(a, b, (*a)->value, limit);
			if (stack_size(*b) == limit)
				limit += chunk_size;
		}
		else
			ra(a);
	}
}

#ifdef TEST_CHUNKS_PUSH
// int	main(int ac, char **av)
// {
// 	t_node	*a;
// 	t_node	*b;

// 	if (ac < 2)
// 		return (0);

// 	a = parsing(ac, av);
// 	if (!a)
// 		return (1);
// 	b = NULL;

// 	ft_printf("=== AVANT ===\n");
// 	print_stack("A", a);
// 	print_stack("B", b);

// 	// Étape 1 : compression
// 	compress_indices(a);

// 	ft_printf("\n=== APRES COMPRESSION ===\n");
// 	print_stack("A", a);

// 	// Étape 2 : push vers B par chunks
// 	push_chunks_to_b(&a, &b, stack_size(a) + stack_size(b));

// 	ft_printf("\n=== APRES PUSH CHUNKS ===\n");
// 	print_stack("A", a);
// 	print_stack("B", b);

// 	clean_free_stack(a);
// 	clean_free_stack(b);
// 	return (0);
// }
#endif
