/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:48:19 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/09 13:40:38 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static void	move_stack(char **tab, t_node **head)
{
	t_node	*max;
	int		r_moves;
	int		rr_moves;

	max = search_vmax_node(head);
	r_moves = clockwise_target_search(head, &max);
	rr_moves = reverse_target_search(head, &max);
	if (rr_moves < r_moves)
		put_multi_inst(tab, rr_moves, RRB);
	else
		put_multi_inst(tab, r_moves, RB);
}

static void	push_inst(char **tab, char stack)
{
	if (stack == STACK_A)
		*tab = put_single_inst(*tab, PB);
	if (stack == STACK_B)
		*tab = put_single_inst(*tab, PA);
}

static void	search_inst_to_b(char **tab, t_node **target, t_node **b_head)
{
	int	r_moves;
	int	rr_moves;

	r_moves = clockwise_target_rev_ins(target, b_head);
	rr_moves = reverse_target_rev_ins(target, b_head);
	if (rr_moves < r_moves)
		put_multi_inst(tab, rr_moves, RRB);
	else
		put_multi_inst(tab, r_moves, RB);
}

void	target_pos_inst(char **tab, t_node **target, t_node **dst_head)
{
	if (!tab)
		return ;
	if (is_max_value(target, dst_head))
	{
		move_stack(tab, dst_head);
		push_inst(tab, STACK_A);
	}
	else if (is_min_value(target, dst_head))
	{
		move_stack(tab, dst_head);
		push_inst(tab, STACK_A);
		*tab = put_single_inst(*tab, RB);
	}
	else
	{
		search_inst_to_b(tab, target, dst_head);
		push_inst(tab, STACK_A);
	}
}
