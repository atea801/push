/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_k_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:22 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:20:03 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief trouve l'indice maximum dans la pile
 *
 * @param node
 * @return int
 */
static int	find_max_idx(t_node *node)
{
	int	max;

	if (!node)
		return (-1);
	max = node->value;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

/**
 * @brief trouve la position d'un indice donné dans la pile
 *
 * @param node
 * @param target
 * @return int
 */
static int	position_of_idx(t_node *node, int target)
{
	int	pos;

	pos = 0;
	while (node)
	{
		if (node->value == target)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

/**
 * @brief déplace les éléments de A vers B avec algorithme de seuil optimisé
 *
 * @param a
 * @param b
 * @param size
 */
static void	move_a_to_b(t_node **a, t_node **b, int size)
{
	int	delta;
	int	threshold;

	if (size > 80)
		delta = size / 20 + 7;
	else
		delta = size / 4 + 1;
	threshold = 0;
	while (*a)
	{
		if ((*a)->value <= threshold + delta)
		{
			pb(a, b);
			if (*b && (*b)->value <= threshold)
				rb(b);
			threshold++;
		}
		else
		{
			ra(a);
		}
	}
}

/**
 * @brief déplace les éléments de B vers A en ordre décroissant optimal
 *
 * @param a
 * @param b
 */
static void	move_b_to_a(t_node **a, t_node **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max = find_max_idx(*b);
		pos = position_of_idx(*b, max);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

/**
 * @brief applique l'algorithme K-Sort optimisé pour trier la pile A
 * en utilisant la pile B comme pile auxiliaire.
 *
 * @param a
 * @param b
 */
void	k_sort(t_node **a, t_node **b)
{
	int	total_size;

	total_size = stack_size(*a);
	compress_indices(*a);
	move_a_to_b(a, b, total_size);
	move_b_to_a(a, b);
}

#ifdef TEST_K_SORT
// int	main(int ac, char **av)
// {
// 	t_node	*a;
// 	t_node	*b;

// 	if (ac < 2)
// 		return (0);

// 	a = parsing(ac, av);
// 	if (!a)
// 		return (1);
// 	b = NULL;

// 	ft_printf("=== AVANT ===\n");
// 	print_stack("A", a);
// 	print_stack("B", b);

// 	k_sort(&a, &b);

// 	ft_printf("\n=== APRES K-SORT ===\n");
// 	print_stack("A", a);
// 	print_stack("B", b);

// 	if (is_sorted(a) && b == NULL)
// 		ft_printf("\nOK: A est triee et B est vide ✅\n");
// 	else
// 		ft_printf("\nKO: pas trie / B non vide ❌\n");

// 	clean_free_stack(a);
// 	clean_free_stack(b);
// 	return (0);
// }
#endif
