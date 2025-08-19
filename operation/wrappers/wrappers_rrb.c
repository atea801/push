/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:33:34 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:30 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief décale tous les nœuds de la pile B d’une position vers le bas,
 * plaçant ainsi le dernier nœud de B en tête de pile.
 *
 * @param b
 */
void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
