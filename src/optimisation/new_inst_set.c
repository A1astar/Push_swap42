/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_inst_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:30:13 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:36:17 by alacroix         ###   ########.fr       */
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

void	change_instructions(char *c1, char *c2, char inst)
{
	*c1 = inst;
	*c2 = SUP;
}

void	change_multi_inst(char *s, int nbr, char inst)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		s[i] = inst;
		i++;
	}
	while (nbr)
	{
		s[i] = SUP;
		i++;
		nbr--;
	}
}

char	*find_optimisations(char *s)
{
	int	i;
	int	s_size;

	i = 0;
	s_size = ft_strlen(s);
	if (s_size < 2)
		return (s);
	while (i < s_size - 1)
	{
		check_simple_combo(&s[i], &s[i + 1]);
		check_multi_combo(&s[i]);
		i++;
	}
	return (put_new_tab(s));
}
