/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_duplicates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:26:15 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:54:03 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * @brief  parcourt les valeurs d’arguments et détecte s’il existe des doublons
 *
 * @param args
 * @return int
 */
int	parsing_check_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
			{
				ft_putendl_fd("Error", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
