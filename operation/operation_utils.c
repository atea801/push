/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:15:31 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 13:42:01 by aautret          ###   ########.fr       */
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
	t_node	*cursor;

	(void)name;
	cursor = head;
	while (cursor)
	{
		printf("%d\n", cursor->value);
		cursor = cursor->next;
	}
}
