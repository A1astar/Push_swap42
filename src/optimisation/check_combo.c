/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_combo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:27:21 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:34:51 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static int	check_mirror(char *s, char inst, int nbr)
{
	int	i;

	i = 0;
	while (s[i] == inst && s[i])
		i++;
	if (i >= nbr)
		return (i);
	else
		return (-1);
}

static bool	can_combine(char *s, int i, char mirror)
{
	if (check_mirror(&s[i], mirror, i) > 0)
		return (true);
	return (false);
}

static void	handle_comb(char *s, int i)
{
	if ((s[0] == RA) && can_combine(s, i, RB))
		change_multi_inst(s, i, RR);
	else if (s[0] == RB && can_combine(s, i, RA))
		change_multi_inst(s, i, RR);
	else if (s[0] == RRA && can_combine(s, i, RRB))
		change_multi_inst(s, i, RRR);
	else if (s[0] == RRB && can_combine(s, i, RRA))
		change_multi_inst(s, i, RRR);
}

void	check_multi_combo(char *s)
{
	int	i;

	i = 0;
	if (s[i] == SUP)
		return ;
	while ((s[i] == s[0]) && s[i])
		i++;
	if (s[i] == '\0')
		return ;
	handle_comb(s, i);
}

void	check_simple_combo(char *c1, char *c2)
{
	if ((*c1 == RA && *c2 == RB) || (*c1 == RB && *c2 == RA))
		change_instructions(c1, c2, RR);
	else if ((*c1 == RRA && *c2 == RRB) || (*c1 == RRB && *c2 == RRA))
		change_instructions(c1, c2, RRR);
	else
		return ;
}
