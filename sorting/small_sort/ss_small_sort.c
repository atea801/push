/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:49:53 by aautret           #+#    #+#             */
/*   Updated: 2025/08/07 20:30:06 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * @brief trie une pile de petite taille (2 ou 3 éléments) en combinant
 * sa/sb, ra/rb et rra/rrb
 *
 * @param a
 * @param b
 */
void	sort_small(t_node **a, t_node **b)
{
	int	len;

	len = stack_size(*a);
	if (len == 2)
		sort_2(a);
	else if (len == 3)
		sort_3(a);
	else if (len == 4 || len == 5)
	{
		push_min_until_three(a, b);
		sort_3(a);
		while (*b)
			pa(a, b);
	}
}

#ifdef TEST_SMALL_SORT

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac < 2)
		return (0);

	a = parsing(ac, av);
	if (!a)
	{
		ft_printf("Erreur de parsing.\n");
		return (1);
	}
	b = NULL;

	ft_printf("Pile AVANT tri :\n");
	print_stack("A", a);

	if (stack_size(a) >= 2 && stack_size(a) <= 5)
		sort_small(&a, &b);
	else
		ft_printf("⚠️ Taille non gérée par sort_small (2 à 5 éléments).\n");

	ft_printf("Pile APRÈS tri :\n");
	print_stack("A", a);

	clean_free_stack(a);
	clean_free_stack(b);
	return (0);
}
#endif
