/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:24:20 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:20:31 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief prend le premier nœud au sommet de la pile A et
 * le place en tête de la pile B
 *
 * @param a
 * @param b
 */
void	pb(t_node **a, t_node **b)
{
	int	value;

	if (!a || !*a)
		return ;
	value = pop_node(a);
	push_node(b, value);
	write(1, "pb\n", 3);
}

#ifdef TEST_PB
// int	main(void)
// {
// 	t_node	*a = NULL;
// 	t_node	*b = NULL;

// 	push_node(&a, 2);
// 	push_node(&a, 1);
// 	push_node(&a, 3);

// 	push_node(&b, 2);
// 	push_node(&b, 1);

// 	print_stack("PILE A", a);
// 	print_stack("PILE B", b);
// 	pb(&a, &b);
// 	print_stack("PILE A", a);
// 	print_stack("PILE B", b);
// 	return (0);
// }
#endif
