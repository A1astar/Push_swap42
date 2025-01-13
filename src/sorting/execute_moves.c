/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:42:04 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 16:52:48 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/moves_set.h"

void	execute_inst_set(char *tab, t_node **a_head, t_node **b_head)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == PA)
			push(b_head, a_head, 'a');
		else if (tab[i] == PB)
			push(a_head, b_head, 'b');
		else if (tab[i] == RA)
			rotate(a_head, 'a');
		else if (tab[i] == RB)
			rotate(b_head, 'b');
		else if (tab[i] == RRA)
			reverse_rotate(a_head, 'a');
		else if (tab[i] == RRB)
			reverse_rotate(b_head, 'b');
		else if (tab[i] == RR)
			rotate_all(a_head, b_head, 'a');
		else if (tab[i] == RRR)
			reverse_rotate_all(a_head, b_head, 'a');
		i++;
	}
}
