/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:18:30 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 17:02:47 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Crée un nouveau nœud de pile avec la valeur donnée
 *
 * Alloue dynamiquement un t_node, initialise son champ value
 * avec la valeur passée en paramètre et son pointeur next à NULL.
 *
 * @param value
 * @return t_node*
 */
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
