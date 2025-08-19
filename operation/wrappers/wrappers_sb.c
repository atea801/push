/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:25:20 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:25:49 by aautret          ###   ########.fr       */
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

#ifdef TEST_SB
// int	main(void)
// {
// 	t_node	*b = NULL;

// 	push_node(&b, 4);
// 	push_node(&b, 9);
// 	push_node(&b, 5);

// 	print_stack("Avant sb", b);
// 	sb(&b);
// 	print_stack("Apres sb", b);

// 	return (0);
// }
#endif
