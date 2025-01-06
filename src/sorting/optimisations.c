/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:30:13 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/06 19:39:45 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	len_of_new_str(char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == '*')
			j++;
		i++;
	}
	return (i - j);
}

static char	*put_new_tab(char *src)
{
	char	*new_tab;
	int		i;
	int 	j;
	int		size;

	i = 0;
	j = 0;
	size = len_of_new_str(src);
	new_tab = ft_calloc(size + 1, sizeof(char));
	if (!new_tab)
		return (NULL);
	while (src[i])
	{
		if (src[i] != '*')
			new_tab[j++] = src[i];
		i++;
	}
	free(src);
	return (new_tab);
}

char	*find_optimisation_to_b(char *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[j] == tab[i] + 1)
			{
				tab[i] += 10;
				tab[j] = '*';
				break ;
			}
			j++;
		}
		i++;
	}
	return (put_new_tab(tab));
}
