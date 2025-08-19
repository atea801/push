/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:30:11 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:21:50 by aautret          ###   ########.fr       */
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

#ifdef TEST_RB
// int	main(void)
// {
// 	t_node *b = NULL;

// 	push_node(&b, 4);
// 	push_node(&b, 3);
// 	push_node(&b, 2);
// 	push_node(&b, 1);

// 	print_stack("Avant rb", b);
// 	rb(&b);
// 	print_stack("Apres rb", b);
// 	return (0);
// }
#endif
