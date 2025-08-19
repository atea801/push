/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:26:13 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:26:17 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief  échange simultanément les deux premiers nœuds au sommet des piles A et B
 *
 * @param a
 * @param b
 */
void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

#ifdef TEST_SS
// int	main(void)
// {
// 	t_node	*a = NULL;
// 	t_node	*b = NULL;

// 	push_node(&a, 2);
// 	push_node(&a, 1);
// 	push_node(&a, 3);

// 	push_node(&b, 8);
// 	push_node(&b, 9);
// 	push_node(&b, 7);

// 	print_stack("PILE A avant ss", a);
// 	print_stack("PILE B avant ss", b);
// 	ss(&a, &b);
// 	print_stack("PILE A apres ss", a);
// 	print_stack("PILE B apres ss", b);
// 	return (0);
// }
#endif
