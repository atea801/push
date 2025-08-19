/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_has_int_overflow.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:13:53 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:54:13 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief détecte si la conversion d’une chaîne de caractères en entier
 * dépasse les limites autorisées pour un int
 *
 * @param str
 * @return int
 */
int	parsing_has_int_overflow(char *str)
{
	int			i;
	int			sign;
	long int	result;

	sign = 1;
	i = 0;
	result = 0;
	if (!str[i])
		return (-1);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (-1);
		if (sign == -1 && (-result < INT_MIN))
			return (-1);
		i++;
	}
	return (1);
}
