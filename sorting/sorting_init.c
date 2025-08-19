/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:45:02 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 17:01:55 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Replace le plus petit élément de la pile a au sommet
 * en effectuant le minimum de rotations possibles :
 * - rotation vers le haut (ra) si le min est dans la première moitié
 * - rotation vers le bas (rra) sinon
 *
 * @param a
 */
static void	rotate_min_top_final(t_node **a)
{
	int	pos;
	int	size;

	pos = find_min_position(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

/**
 * @brief Initialise le tri de la pile a en choisissant la stratégie adaptée :
 * - ne fait rien si la pile est vide ou déjà triée
 * - utilise sort_small si la pile contient 5 éléments ou moins
 * - applique k_sort pour les piles plus grandes
 * - termine en plaçant le plus petit élément en haut de la pile a
 *
 * @param a
 */
void	init_sort(t_node **a)
{
	t_node	*b;
	int		len;

	if (!a || !*a || is_sorted(*a))
		return ;
	b = NULL;
	len = stack_size(*a);
	if (len <= 5)
		return (sort_small(a, &b));
	k_sort(a, &b);
	rotate_min_top_final(a);
}
