/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:03:04 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 11:27:42 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	r = (char *) malloc ((len + 1) * sizeof (char));
	if (!r)
		return (NULL);
	ft_memcpy(r, s1 + start, len);
	r[len] = '\0';
	return (r);
}
// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 		printf("ft_strtrim   || %s\n", ft_strtrim(av[1], av[2]));
// 	return (0);
// }
