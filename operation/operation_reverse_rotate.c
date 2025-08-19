/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:37:45 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:13:31 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief  décale tous les nœuds d’une position vers le bas,
 * plaçant ainsi le dernier nœud en tête de la pile
 *
 * @param head
 */
void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*prelast;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	prelast = NULL;
	while (last->next)
	{
		prelast = last;
		last = last->next;
	}
	prelast->next = NULL;
	last->next = *head;
	*head = last;
}
