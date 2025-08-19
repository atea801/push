/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_push_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:49:06 by aautret           #+#    #+#             */
/*   Updated: 2025/08/08 20:05:02 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the chunk size objectcalcule et renvoie la taille optimale d’un
 * chunk en fonction du nombre total d’éléments à trier.
 *
 * @param total_size
 * @return int
 */
int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (total_size / 5);
	return (total_size / 11);
}

/**
 * @brief déplace de A vers B les nœuds dont la valeur est inférieure ou égale
 * à une limite donnée.
 *
 * @param a
 * @param b
 * @param value
 * @param limit
 */
void	push_current_to_b(t_node **a, t_node **b, int value, int limit)
{
	if (value <= limit)
	{
		pb(a, b);
		if (value < limit - (limit / 2))
			rb(b);
	}
	else
		ra(a);
}
