/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pop_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:50:32 by aautret           #+#    #+#             */
/*   Updated: 2025/08/06 14:51:57 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief  pop retire le premier nœud d’une pile et renvoie ce nœud pour
 * éventuellement l’utiliser
 *
 * @param head
 * @return int
 */
int	pop_node(t_node **head)
{
	int		value;
	t_node	*first;

	if (!head || !*head)
		return (0);
	first = *head;
	value = first->value;
	*head = first->next;

	free(first);
	return (value);
}
