/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exe_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:09:34 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:21:29 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static void	push_inst(t_node **a_head, t_node **b_head, char inst)
{
	if (inst == PA)
		push(b_head, a_head, '*');
	if (inst == PB)
		push(a_head, b_head, '*');
}

static void	rotate_inst(t_node **a_head, t_node **b_head, char inst)
{
	if (inst == RA)
		rotate(a_head, '*');
	if (inst == RB)
		rotate(b_head, '*');
	if (inst == RR)
		rotate_all(a_head, b_head, '*');
}

static void	reverse_rotate_inst(t_node **a_head, t_node **b_head, char inst)
{
	if (inst == RRA)
		reverse_rotate(a_head, '*');
	if (inst == RRB)
		reverse_rotate(b_head, '*');
	if (inst == RRR)
		reverse_rotate_all(a_head, b_head, '*');
}

static void	swap_inst(t_node **a_head, t_node **b_head, char inst)
{
	if (inst == SA)
		swap(a_head, '*');
	if (inst == SB)
		swap(b_head, '*');
	if (inst == SS)
		swap_all(a_head, b_head, '*');
}

void	check_execute_inst(t_node **a_head, t_node **b_head, char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		push_inst(a_head, b_head, tab[i]);
		rotate_inst(a_head, b_head, tab[i]);
		reverse_rotate_inst(a_head, b_head, tab[i]);
		swap_inst(a_head, b_head, tab[i]);
		i++;
	}
}
