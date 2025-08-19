/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_is_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:28:46 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:17:49 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief vérifie si les nœuds d’une pile sont déjà classés en ordre croissant
 *
 * @param a
 * @return int
 */
int	is_sorted(t_node *a)
{
	t_node	*current;

	current = a;
	while (current && current -> next)
	{
		if ((current -> value) > (current -> next -> value))
			return (0);
		current = current -> next;
	}
	return (1);
}

#ifdef TEST_IS_SORTED
// int	main(void)
// {
// 	t_node	*pile1 = NULL;
// 	t_node	*pile2 = NULL;

// 	// Cas 1 : pile triée (1 -> 2 -> 3)
// 	pile1 = new_node(1);
// 	pile1->next = new_node(2);
// 	pile1->next->next = new_node(3);
// 	ft_printf("Pile 1 triée ? %d\n", is_sorted(pile1)); // attendu : 1

// 	// Cas 2 : pile non triée (3 -> 2 -> 1)
// 	pile2 = new_node(3);
// 	pile2->next = new_node(2);
// 	pile2->next->next = new_node(1);
// 	ft_printf("Pile 2 triée ? %d\n", is_sorted(pile2)); // attendu : 0

// 	// Libération mémoire
// 	clean_free_stack(pile1);
// 	clean_free_stack(pile2);

// 	return (0);
// }
#endif
