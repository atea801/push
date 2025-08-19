/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:19:16 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:09:13 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief push prend le premier nœud d’une pile et le place en tête
 * de l’autre pile.
 *
 * @param head
 * @param nb
 */
void	push_node(t_node **head, int nb)
{
	t_node	*new;

	if (!head)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = nb;
	new->next = *head;
	*head = new;
}
