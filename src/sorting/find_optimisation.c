/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:30:13 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 13:00:01 by alacroix         ###   ########.fr       */
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

/*char	*find_optimisations(char *s)
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
		}
		i++;
	}
	return (put_new_tab(s));
}*/
static void	check_combo(char *c1, char *c2)
{
	if ((*c1 == RA && *c2 == RB) || (*c1 == RB && *c2 == RA))
		change_instructions(c1, c2, RR);
	else if ((*c1 == RRA && *c2 == RRB) || (*c1 == RRB && *c2 == RRA))
		change_instructions(c1, c2, RRR);
	else
		return ;
}

char	*find_optimisations(char *s)
{
	int i;
	int s_size;

	i = 0;
	s_size = ft_strlen(s);
	if (s_size < 2)
		return (s);
	while (i < s_size - 1)
	{
		check_combo(&s[i], &s[i + 1]);
		i++;
	}
	return (put_new_tab(s));
}
