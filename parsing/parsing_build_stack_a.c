/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_build_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:54:30 by aautret           #+#    #+#             */
/*   Updated: 2025/08/13 11:27:59 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"


/**
 * @brief Ajoute un nœud à la fin de la pile
 *
 * @param a
 * @param new_node
 */
static void	append_node(t_node **a, t_node *new_node)
{
	t_node	*last;

	if (!*a)
	{
		*a = new_node;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

/**
 * @brief Construit la pile a à partir d'un tableau args
 *
 * @param args
 * @return t_node*
 */
t_node	*parsing_build_stack_a(char **args)
{
	t_node	*a;
	t_node	*new_node;
	int		i;
	int		value;

	i = 0;
	a = NULL;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			clean_free_stack(a);
			return (NULL);
		}
		new_node->value = value;
		new_node->next = NULL;
		append_node(&a, new_node);
		i++;
	}
	return (a);
}


#ifdef TEST_BUILD_STACK
// int	main(int ac, char **av)
// {
// 	char	**args;
// 	t_node	*a;

// 	args = parsing_split_args(ac, av); // ta fonction point 1
// 	if (!args)
// 	{
// 		ft_printf("Parsing échoué ou arguments invalides.\n");
// 		return (1);
// 	}
// 	a = parsing_build_stack_a(args);
// 	if (!a)
// 	{
// 		ft_printf("Erreur : impossible de construire la pile.\n");
// 		return (1);
// 	}
// 	print_stack("Pile A", a);
// 	clean_free_stack(a);
// 	return (0);
// }
#endif
