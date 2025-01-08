/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:48:19 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:37 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static void	move_stack(char **tab, t_node **head, char stack)
{
	t_node	*max;
	int		r_moves;
	int		rr_moves;

	if (stack == STACK_B)
		return ;
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

static void	search_inst_to_a(char **tab, t_node **target, t_node **a_head)
{
	int	r_moves;

	r_moves = clockwise_target_ins(target, a_head);
	put_multi_inst(tab, r_moves, RA);
}

static void	check_a(char **tab, t_node **target, t_node **a_head)
{
	long	last_value;
	long	current_value;
	long	target_value;

	last_value = ((t_node *)(*a_head)->prev)->value;
	current_value = (*a_head)->value;
	target_value = (*target)->value;
	if(((t_node *)(*a_head)->prev)->index == 2)
	{
		search_inst_to_a(tab, target, a_head);
		return ;
	}
	if((last_value < current_value) && (last_value > target_value))
		*tab = put_single_inst(*tab, RRA);
}

void	target_pos_inst(char **tab, t_node **target, t_node **dst_head,
		char stack)
{
	if (!tab)
		return ;
	if (is_max_value(target, dst_head) && stack == STACK_A)
	{
		move_stack(tab, dst_head, stack);
		push_inst(tab, stack);
	}
	else if (is_min_value(target, dst_head) && stack == STACK_A)
	{
		move_stack(tab, dst_head, stack);
		push_inst(tab, stack);
		*tab = put_single_inst(*tab, RB);
	}
	else
	{
		if (stack == STACK_A)
			search_inst_to_b(tab, target, dst_head);
		else
			check_a(tab, target, dst_head);
		push_inst(tab, stack);
	}
}
