/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:12:52 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:30:45 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  trie une pile de exactement deux nœuds en effectuant un swap
 * si les deux valeurs ne sont pas dans l’ordre croissant.
 *
 * @param a
 */
void	sort_2(t_node **a)
{
	if (*a && (*a)->next && ((*a)->value > (*a)->next->value))
		sa(a);
}
