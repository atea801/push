/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_reverse_min_to_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:16:33 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:28:48 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief utilise la rotation inverse (rra ou rrb) pour amener le nœud de
 * plus petite valeur au sommet de la pile.
 *
 * @param a
 * @param pos
 * @param size
 */
void	reverse_min_to_top(t_node **a, int pos, int size)
{
	while (pos++ < size)
		rra(a);
}
