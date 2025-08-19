/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_push_min_until_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:17:21 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:28:20 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief déplace successivement le nœud de plus petite valeur de la pile A
 * vers la pile B jusqu’à ce qu’il ne reste plus que trois nœuds dans A.
 *
 * @param a
 * @param b
 */
void	push_min_until_three(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	while (stack_size(*a) > 3)
	{
		min_pos = find_min_position(*a);
		size = stack_size(*a);
		if (min_pos <= size / 2)
			rotate_min_to_top(a, min_pos);
		else
			reverse_min_to_top(a, min_pos, size);
		pb(a, b);
	}
}
