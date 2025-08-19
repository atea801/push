/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_stack_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:05:23 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:53:37 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  retourne le nombre total de nœuds présents dans une pile chaînée
 *
 * @param a
 * @return int
 */
int	stack_size(t_node *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a -> next;
	}
	return (count);
}
