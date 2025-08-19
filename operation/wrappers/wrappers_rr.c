/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:31:04 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:22:41 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief exécute simultanément ra et rb, c’est-à-dire qu’elle fait remonter
 * en fin de pile les premiers nœuds des piles A et B en une seule instruction
 *
 * @param a
 * @param b
 */
void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

#ifdef TEST_RR
// int	main(void)
// {
// 	t_node	*a = NULL;
// 	t_node	*b = NULL;

// 	push_node(&a, 4);
// 	push_node(&a, 3);
// 	push_node(&a, 2);
// 	push_node(&a, 1);

// 	push_node(&b, 5);
// 	push_node(&b, 6);
// 	push_node(&b, 7);
// 	push_node(&b, 8);

// 	print_stack("PILE A avant RR", a);
// 	print_stack("PILE B avant RR", b);
// 	rr(&a, &b);
// 	print_stack("PILE A apres RR", a);
// 	print_stack("PILE B apres RR", b);
// }
#endif
