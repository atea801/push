/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:30:11 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:14 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief décale tous les nœuds de la pile B d’une position vers le haut,
 * plaçant ainsi le premier nœud de B en fin de pile
 *
 * @param b
 */
void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
