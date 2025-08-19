/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_ra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:28:59 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:09 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief décale tous les nœuds de la pile A d’une position vers le haut,
 * plaçant ainsi le premier nœud de A en fin de pile
 *
 * @param a
 */
void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
