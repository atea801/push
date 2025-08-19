/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compress_indices.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:43:40 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 16:21:13 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * @brief copie les valeurs de la pile A dans un tableau d’entiers
 * de taille donnée.
 *
 * @param a
 * @param size
 * @return int*
 */
static int	*stack_to_array(t_node *a, int size)
{
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

/**
 * @brief parcourt chaque élément de la pile et remplace sa valeur
 * originale par son rang (index) dans le tableau des valeurs triées.
 *
 * @param a
 * @param sorted
 * @param size
 */
static void	replace_with_indices(t_node *a, const int *sorted, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size && sorted[i] != a->value)
			i++;
		a->value = i;
		a = a->next;
	}
}

/**
 * @brief copie la pile dans un tableau, trie le tableau,
 * remplace chaque valeur de la pile par son ibdex range dans le tri
 *
 * @param a
 * @return * void
 */
void	compress_indices(t_node *a)
{
	int	size;
	int	*arr;

	size = stack_size(a);
	if (size <= 0)
		return ;
	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	sort_int_array(arr, size);
	replace_with_indices(a, arr, size);
	free(arr);
}
