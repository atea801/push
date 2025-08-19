/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_is_valid_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:51:05 by aautret           #+#    #+#             */
/*   Updated: 2025/08/05 16:52:26 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief vérifie qu’une chaîne de caractères représente un entier valide
 * (format correct et dans les limites de l’int)
 *
 * @param nbr
 * @return int
 */
int	parsing_is_valid_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	if (!nbr[i])
		return (-1);
	while (nbr[i])
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

#ifdef TEST_IS_VALID_NBR
	// int	main(int ac, char **av)
	// {
	// 	if (ac < 2)
	// 	{
	// 		ft_printf("Fournir une chaîne à tester.\n");
	// 		return (1);
	// 	}
	// 	ft_printf("%d\n", parsing_is_valid_number(av[1]));
	// 	return (0);
	// }
#endif
