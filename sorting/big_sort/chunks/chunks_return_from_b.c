/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_return_from_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:49:24 by aautret           #+#    #+#             */
/*   Updated: 2025/08/11 10:02:53 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * @brief retourne l'index du plus grand élément dans B
 *
 * @param b
 * @return int
 */
int	find_max_position(t_node *b)
{
	int	pos;
	int	max_pos;
	int	max_val;

	pos = 0;
	max_pos = 0;
	max_val = b->value;
	while (b)
	{
		if (b->value > max_val)
		{
			max_val = b->value;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

/**
 * @brief déplace le nœud ayant la valeur maximale dans la pile B
 * jusqu’au sommet, en effectuant soit des rotations (rb) soit
 * des rotations inverses (rrb) selon sa position (pos) pour
 * minimiser le nombre de mouvements.
 *
 * @param b
 * @param pos
 */
void	rotate_max_to_top(t_node **b, int pos)
{
	while (pos-- > 0)
		rb(b);
}

/**
 * @brief place le nœud de valeur maximale en sommet de pile B
 * en utilisant des rotations inverses optimisées selon
 * sa position et la taille de la pile
 *
 * @param b
 * @param pos
 * @param size
 */
void	reverse_max_to_top(t_node **b, int pos, int size)
{
	while (pos++ < size)
		rrb(b);
}

void	rotate_min_to_top(t_node **a, int pos)
{
	while (pos-- > 0)
		ra(a);
}

/**
 * @brief remonte le max en haut de B puis pa vers A, jusqu'à vider B
 *
 * @param a
 * @param b
 */
void	push_back_to_a(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_position(*b);
		if (pos <= size / 2)
			rotate_max_to_top(b, pos);
		else
			reverse_max_to_top(b, pos, size);
		pa(a, b);
	}
}
