/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:48:19 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 16:58:56 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static void move_stack(char **tab, t_node **head)
{
	t_node *max;
	int r_moves;
	int	rr_moves;

	max = search_vmax_node(head);
	r_moves = clockwise_target_search(head, &max);
	rr_moves = reverse_target_search(head, &max);
	if (rr_moves < r_moves)
		put_multi_inst(tab, rr_moves, RRB);
	else
		put_multi_inst(tab, r_moves, RB);
}

static void push_inst(char **tab, char stack)
{
	if (stack == STACK_A)
		*tab = put_single_inst(*tab, PB);
	if (stack == STACK_B)
		*tab = put_single_inst(*tab, PA);
}

static void	search_inst(char **tab, t_node **target, t_node **dst_head, char stack)
{
	int	r_moves;
	int	rr_moves;

	r_moves = clockwise_target_insersion(target, dst_head);
	rr_moves = reverse_target_insersion(target, dst_head);
	if (rr_moves < r_moves)
	{
		if(stack == STACK_A)
			put_multi_inst(tab, rr_moves, RRB);
		else
			put_multi_inst(tab, rr_moves, RRA);
	}
	else
	{
		if(stack == STACK_A)
			put_multi_inst(tab, r_moves, RB);
		else
			put_multi_inst(tab, r_moves, RA);
	}
}

void	target_pos_inst(char **tab, t_node **target, t_node **dst_head, char stack)
{
	if (!tab)
		return ;
	if(stack == STACK_A)
		move_stack(tab, dst_head);
	if (is_max_value(target, dst_head) == true)
		push_inst(tab, stack);
	else if (is_min_value(target, dst_head) == true)
	{
		push_inst(tab, stack);
		if (stack == STACK_A)
			*tab = put_single_inst(*tab, RB);
		else
			*tab = put_single_inst(*tab, RA);
	}
	else
	{
		search_inst(tab, target, dst_head, stack);
		push_inst(tab, stack);
	}
}
