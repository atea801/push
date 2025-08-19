/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:49:53 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 16:02:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * @brief trie une pile de petite taille (2 ou 3 éléments) en combinant
 * sa/sb, ra/rb et rra/rrb
 *
 * @param a
 * @param b
 */
void	sort_small(t_node **a, t_node **b)
{
	int	len;

	len = stack_size(*a);
	if (len == 2)
		sort_2(a);
	else if (len == 3)
		sort_3(a);
	else if (len == 4 || len == 5)
	{
		push_min_until_three(a, b);
		sort_3(a);
		while (*b)
			pa(a, b);
	}
}
