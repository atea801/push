/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:27:47 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:19:37 by aautret          ###   ########.fr       */
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

#ifdef TEST_PA
// int	main(void)
// {
// 	t_node	*a = NULL;
// 	t_node	*b = NULL;

// 	push_node(&a, 4);
// 	push_node(&a, 3);
// 	push_node(&a, 2);
// 	push_node(&a, 1);

// 	push_node(&b, 2);
// 	push_node(&b, 1);

// 	print_stack("PILE A", a);
// 	print_stack("PILE B", b);
// 	pa(&a, &b);
// 	print_stack("PILE A", a);
// 	print_stack("PILE B", b);
// 	return (0);
// }
#endif
