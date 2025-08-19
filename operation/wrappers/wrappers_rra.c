/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:32:45 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:24 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief  décale tous les nœuds de la pile A d’une position vers le bas,
 * plaçant ainsi le dernier nœud de A en tête de pile
 *
 * @param a
 */
void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
