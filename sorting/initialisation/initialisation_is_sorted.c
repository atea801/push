/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_is_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:28:46 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:53:32 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief vérifie si les nœuds d’une pile sont déjà classés en ordre croissant
 *
 * @param a
 * @return int
 */
int	is_sorted(t_node *a)
{
	t_node	*current;

	current = a;
	while (current && current -> next)
	{
		if ((current -> value) > (current -> next -> value))
			return (0);
		current = current -> next;
	}
	return (1);
}
