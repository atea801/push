/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:45:02 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:53:44 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_top_final(t_node **a)
{
	int	pos;
	int	size;

	pos = find_min_position(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

void	init_sort(t_node **a)
{
	t_node	*b;
	int		len;

	if (!a || !*a || is_sorted(*a))
		return ;
	b = NULL;
	len = stack_size(*a);
	if (len <= 5)
		return (sort_small(a, &b));
	k_sort(a, &b);
	rotate_min_top_final(a);
}
