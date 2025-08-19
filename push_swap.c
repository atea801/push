/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:43:06 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 13:13:47 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	t_node	*a;

	a = parsing(ac, av);
	if (!a)
		return (1);
	init_sort(&a);
	clean_free_stack(a);
	return (0);
}
