/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:32:45 by aautret           #+#    #+#             */
/*   Updated: 2025/08/11 10:24:46 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief  décale tous les nœuds de la pile A d’une position vers le bas,
 * plaçant ainsi le dernier nœud de A en tête de pile
 *
 * @param a
 */
void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

#ifdef TEST_RRA
// int	main(void)
// {
// 	t_node	*a = NULL;

// 	push_node(&a, 4);
// 	push_node(&a, 3);
// 	push_node(&a, 2);
// 	push_node(&a, 1);

// 	print_stack("Avant rra", a);
// 	rra(&a);
// 	print_stack("Apres rra", a);
// 	return (0);
// }
#endif
