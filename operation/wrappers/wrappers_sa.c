/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_sa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:23:06 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:55:41 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief échange les deux premiers nœuds au sommet de la pile A
 *
 * @param a
 */
void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
