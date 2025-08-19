/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:39:38 by aautret           #+#    #+#             */
/*   Updated: 2025/08/13 11:27:59 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief  vérifie que chaque argument est un entier valide
 * (format, pas de dépassement) et qu'il n'y a pas de doublons
 *
 * @param args
 * @return int
 */
int	parsing_validate_numbers(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (parsing_is_valid_number(args[i]) == -1
			|| parsing_has_int_overflow(args[i]) == -1)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

#ifdef TEST_VALIDATE_NBR
// int	main(int ac, char **av)
// {
// 	char	**args;
// 	int		result;

// 	args = parsing_split_args(ac, av);
// 	if (!args)
// 	{
// 		ft_printf("Parsing a échoué ou aucun argument valide.\n");
// 		return (0);
// 	}
// 	result = parsing_validate_numbers(args);
// 	if (result == 1)
// 		ft_printf("✅ Tous les éléments sont valides.\n");
// 	else
// 		ft_printf("❌ Erreur détectée.\n");
// 	return (0);
// }
#endif
