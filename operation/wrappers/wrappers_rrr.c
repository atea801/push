/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:34:42 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:24:29 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief exécute simultanément rra et rrb, c’est-à-dire qu’elle fait
 * descendre le dernier nœud de chaque pile en tête en une seule instruction
 *
 * @param a
 * @param b
 */
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 3);
}

#ifdef TEST_RRR
// int	main(void)
// {
// 	t_node	*a = NULL;
// 	t_node	*b = NULL;

// 	push_node(&a, 8);
// 	push_node(&a, 7);
// 	push_node(&a, 6);
// 	push_node(&a, 5);

// 	push_node(&b, 4);
// 	push_node(&b, 3);
// 	push_node(&b, 2);
// 	push_node(&b, 1);

// 	print_stack("PILE A avant rrr", a);
// 	print_stack("PILE B avant rrr", b);
// 	rrr(&a, &b);
// 	print_stack("PILE A apres rrt", a);
// 	print_stack("PILE B apres rrt", b);
// 	return (0);
// }
#endif
