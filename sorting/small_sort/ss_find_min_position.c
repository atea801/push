/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_find_min_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:14:23 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:27:46 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief retourne la position (indice depuis le sommet) du nœud contenant
 * la valeur minimale dans la pile.
 *
 * @param a
 * @return int
 */
int	find_min_position(t_node *a)
{
	int	pos;
	int	min_pos;
	int	min_value;

	pos = 0;
	min_pos = 0;
	min_value = a->value;
	while (a)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}
