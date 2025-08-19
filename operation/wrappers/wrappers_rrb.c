/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:33:34 by aautret           #+#    #+#             */
/*   Updated: 2025/08/08 19:51:37 by aautret          ###   ########.fr       */
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

#ifdef TEST_RRB
// int	main(void)
// {
// 	t_node	*b = NULL;

// 	push_node(&b, 4);
// 	push_node(&b, 3);
// 	push_node(&b, 2);
// 	push_node(&b, 1);

// 	print_stack("Avant rrb", b);
// 	rra(&b);
// 	print_stack("Apres rra", b);
// 	return (0);
// }
#endif
