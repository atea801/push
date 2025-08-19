/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:28:33 by aautret           #+#    #+#             */
/*   Updated: 2025/08/19 14:01:30 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/**
 * @brief compte les éléments dans un argument splitté
 *
 * @param arg
 * @return int
 */
static int	count_elements_in_arg(char *arg)
{
	char	**split;
	int		count;
	int		j;

	if (!arg || !*arg || is_only_spaces(arg))
		return (0);
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	count = 0;
	j = 0;
	while (split[j])
	{
		count++;
		j++;
	}
	clean_free_split(split);
	return (count);
}

/**
 * @brief compte le nombre total d'éléments après split de tous les arguments
 *
 * @param ac
 * @param av
 * @return int
 */
static int	count_total_elements(int ac, char **av)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < ac)
	{
		total += count_elements_in_arg(av[i]);
		i++;
	}
	return (total);
}

/**
 * @brief ajoute les éléments d'un argument splitté au résultat
 *
 * @param result
 * @param result_index
 * @param arg
 * @return int
 */
static int	add_split_to_result(char **result, int *result_index, char *arg)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		result[*result_index] = ft_strdup(split[j]);
		if (!result[*result_index])
		{
			clean_free_split(split);
			clean_free_split(result);
			return (-1);
		}
		(*result_index)++;
		j++;
	}
	clean_free_split(split);
	return (0);
}

/**
 * @brief traite tous les arguments en les splittant et en les concaténant
 *
 * @param ac
 * @param av
 * @return char**
 */
static char	**parsing_split_all_args(int ac, char **av)
{
	int		total_count;
	char	**result;
	int		result_index;
	int		i;

	total_count = count_total_elements(ac, av);
	if (total_count == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (total_count + 1));
	if (!result)
		return (NULL);
	result_index = 0;
	i = 1;
	while (i < ac && result)
	{
		if (av[i] && *av[i] && !is_only_spaces(av[i]))
			if (add_split_to_result(result, &result_index, av[i]) == -1)
				return (NULL);
		i++;
	}
	result[result_index] = NULL;
	return (result);
}

/**
 * @brief segmente toutes les chaînes d'arguments fournies
 * (qu'il y en ait une ou plusieurs)en éléments individuels à l'aide
 * d'espaces comme délimiteurs.
 *
 * @param ac
 * @param av
 * @return char**
 */
char	**parsing_split_args(int ac, char **av)
{
	if (ac == 1)
		return (NULL);
	return (parsing_split_all_args(ac, av));
}

#ifdef TEST_SPLIT_ARGS
// int	main(int ac, char **av)
// {
// 	char	**parsed;
// 	int		i;

// 	parsed = parsing_split_args(ac, av);
// 	if (!parsed)
// 	{
// 		ft_printf("Parsing a échoué ou aucun argument valide.\n");
// 		return (0);
// 	}
// 	// Afficher le résultat
// 	i = 0;
// 	while (parsed[i])
// 	{
// 		printf("parsed[%d] = \"%s\"\n", i, parsed[i]);
// 		i++;
// 	}
// 	// Libération mémoire
// 	clean_free_split(parsed);

// 	return (0);
// }
#endif
