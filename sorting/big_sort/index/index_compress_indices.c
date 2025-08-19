/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compress_indices.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:43:40 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:27:44 by aautret          ###   ########.fr       */
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
 * @brief remplace chaque valeur de la pile A par son indice correspondant
 * dans le tableau trié fourni.
 *
 * @param a
 * @param arr
 * @param size
 */
// static void	replace_with_indices(t_node *a, int *arr, int size)
// {
// 	int	i;

// 	while (a)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (a->value == arr[i])
// 			{
// 				a->value = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		a = a->next;
// 	}
// }

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

// void	compress_indices(t_node *a)
// {
// 	int	size;
// 	int	*arr;

// 	size = stack_size(a);
// 	if (size <= 0)
// 		return ;
// 	arr = stack_to_array(a, size);
// 	if (!arr)
// 		return ;
// 	sort_int_array(arr, size);
// 	replace_with_indices(a, arr, size);
// 	free(arr);
// }

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

// DEBUG: affiche les valeurs originales à partir des indices compressés
/*static void	print_stack_with_originals(const char *name, t_node *a,
	const int *sorted)
{
	ft_printf("%s (originals):\n", name);
	while (a) {
		ft_printf("%d\n", sorted[a->value]); // a->value est un rang 0..n-1
		a = a->next;
	}
}*/

#ifdef TEST_BIG_SORT_INDEX
// int main(int ac, char **av)
// {
// 	t_node	*a;
// 	int		*arr;
// 	int		size;

// 	if (ac < 2)
// 		return (0);

// 	a = parsing(ac, av);
// 	if (!a)
// 		return (1);

// 	size = stack_size(a);
// 	arr = stack_to_array(a, size);
// 	if (!arr)
// 		return (1);
// 	sort_int_array(arr, size);

// 	compress_indices(a);

// 	ft_printf("APRES (indices):\n");
// 	print_stack("A", a);

// 	ft_printf("APRES (originals):\n");
// 	print_stack_with_originals("A", a, arr);

// 	free(arr);
// 	clean_free_stack(a);
// 	return (0);
// }
#endif
