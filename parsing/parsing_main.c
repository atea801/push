/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:18:24 by aautret           #+#    #+#             */
/*   Updated: 2025/08/13 12:57:15 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief analyse et valide les arguments du programme,
 * puis construit et retourne la pile initiale sous forme de liste chaînée.
 *
 * @param ac
 * @param av
 * @return t_node*
 */
t_node	*parsing(int ac, char **av)
{
	char	**args;
	t_node	*a;

	if (ac == 1)
		return (NULL);
	args = parsing_split_args(ac, av);
	if (!args)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	if (parsing_validate_numbers(args) == -1)
	{
		clean_free_split(args);
		return (NULL);
	}
	if (parsing_check_duplicates(args) == -1)
	{
		clean_free_split(args);
		return (NULL);
	}

	a = parsing_build_stack_a(args);
	clean_free_split(args);
	if (!a)
		return (NULL);

	return (a);
}

#ifdef TEST_PARSING
int	main(int ac, char **av)
{
	t_node	*a;

	a = parsing(ac, av);
	if (!a)
	{
		ft_printf("Parsing échoué ou erreur détectée.\n");
		return (1);
	}
	print_stack("Pile A", a);
	clean_free_stack(a);
	return (0);
}
#endif
