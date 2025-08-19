/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:15:31 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:18:14 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "ft_printf.h"

/**
 * @brief affiche les valeurs de chaque nœud de la pile,
 * du sommet jusqu’au bas, dans l’ordre.
 *
 * @param name
 * @param head
 */
void	print_stack(const char *name, t_node *head)
{
	// 1) Nom de la pile
	ft_printf("%s: \n", name);

	// 2) Parcours de chaque nœud
	t_node *cursor = head;
	while (cursor)
	{
		// 3) Affichage de la valeur
		printf("%d\n", cursor->value);
		cursor = cursor->next;
	}

	// 4) Fin de ligne
	// printf("\n");
}
