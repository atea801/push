/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:09:53 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:17:08 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief décale tous les nœuds d’une position vers le haut,
 * plaçant ainsi le premier nœud en fin de pile
 *
 * @param head
 */
void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*parcour;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first -> next;
	*head = second;
	parcour = *head;
	while (parcour->next)
	{
		parcour = parcour -> next;
	}
	parcour -> next = first;
	first -> next = NULL;
}
