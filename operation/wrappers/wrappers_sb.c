/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:25:20 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:46 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief échange les deux premiers nœuds au sommet de la pile B
 *
 * @param b
 */
void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
