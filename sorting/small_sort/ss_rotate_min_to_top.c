/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rotate_min_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:15:38 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:29:17 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief utilise la rotation (ra ou rb) pour placer le nœud de valeur
 * minimale au sommet de la pile.
 *
 * @param a
 * @param pos
 */
void	rotate_min_to_top(t_node **a, int pos)
{
	while (pos-- > 0)
		ra(a);
}
