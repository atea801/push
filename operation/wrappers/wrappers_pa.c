/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:27:47 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:54:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief prend le premier nœud au sommet de la pile B
 * et le place en tête de la pile A
 *
 * @param a
 * @param b
 */
void	pa(t_node **a, t_node **b)
{
	int	value;

	if (!b || !*b)
		return ;
	value = pop_node(b);
	push_node(a, value);
	write(1, "pa\n", 3);
}
