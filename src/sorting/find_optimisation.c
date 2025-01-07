/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:30:13 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 19:55:15 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static int	len_of_new_str(char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == SUP)
			j++;
		i++;
	}
	return (i - j);
}

static char	*put_new_tab(char *src)
{
	char	*new_tab;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = len_of_new_str(src);
	new_tab = ft_calloc(size + 1, sizeof(char));
	if (!new_tab)
		return (NULL);
	while (src[i])
	{
		if (src[i] != SUP)
			new_tab[j++] = src[i];
		i++;
	}
	free(src);
	return (new_tab);
}

static void	change_instructions(char *c1, char *c2, char inst)
{
	*c1 = inst;
	*c2 = SUP;
}

char	*find_optimisations(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if ((s[j] == RB && s[i] == RA) || (s[j] == RA && s[i] == RB))
			{
				change_instructions(&s[i], &s[j], RR);
				break ;
			}
			else if ((s[j] == RRB && s[i] == RRA) || (s[j] == RRA
					&& s[i] == RRB))
			{
				change_instructions(&s[i], &s[j], RRR);
				break ;
			}
			j++;
		}
		i++;
	}
	return (put_new_tab(s));
}
