/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_stack_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:05:23 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:18:03 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  retourne le nombre total de nœuds présents dans une pile chaînée
 *
 * @param a
 * @return int
 */
int	stack_size(t_node *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a -> next;
	}
	return (count);
}

#ifdef TEST_STACK_SIZE
// int	main(void)
// {
// 	t_node	*pile1;
// 	t_node	*pile2;
// 	t_node	*pile3;

// 	pile1 = NULL;
// 	pile2 = NULL;
// 	pile3 = NULL;
// 	ft_printf("Taille pile vide : %d\n", stack_size(pile1));
// 	pile2 = new_node(42);
// 	ft_printf("Taille pile avec 1 élément : %d\n", stack_size(pile2));
// 	pile3 = new_node(1);
// 	pile3->next = new_node(2);
// 	pile3->next->next = new_node(3);
// 	ft_printf("Taille pile avec 3 éléments : %d\n", stack_size(pile3));
// 	clean_free_stack(pile2);
// 	clean_free_stack(pile3);
// 	return (0);
// }
#endif
