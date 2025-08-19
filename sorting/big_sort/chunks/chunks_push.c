/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:48:37 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:53:17 by aautret          ###   ########.fr       */
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
