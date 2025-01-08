/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:19:46 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 18:05:31 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

static void push_head_first(t_node **a_head)
{
	t_node *min;

	min = search_vmin_node(a_head);
	if(clockwise_target_search(a_head, &min) < reverse_target_search(a_head, &min))
		while(*a_head != min)
			rotate(a_head, 'a');
	else
		while(*a_head != min)
			reverse_rotate(a_head, 'a');
}

static void	push_head_inst(char **tab, t_node **target, t_node **src_head)
{
	int	r_moves;
	int	rr_moves;

	r_moves = clockwise_target_search(src_head, target);
	rr_moves = reverse_target_search(src_head, target);
	if (r_moves < rr_moves)
		put_multi_inst(tab, r_moves, RA);
	else
		put_multi_inst(tab, rr_moves, RRA);
}

static char	*inst_set_of(t_node **current, t_node **src_head, t_node **dst_head,
		char stack)
{
	char	*tab;

	tab = ft_calloc(1, sizeof(char));
	if (!tab)
		return (NULL);
	if (stack == STACK_A)
		push_head_inst(&tab, current, src_head);
	target_pos_inst(&tab, current, dst_head, stack);
	tab = find_optimisations(tab);
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*find_cheapest_inst_set(t_node **src_head, t_node **dst_head,
		char stack)
{
	t_node	*current;
	char	*current_set;
	char	*target_set;

	current = *src_head;
	current_set = NULL;
	target_set = NULL;
	while (1)
	{
		current_set = inst_set_of(&current, src_head, dst_head, stack);
		if (!current_set)
			return (free(target_set), NULL);
		if (!target_set || ft_strlen(current_set) < ft_strlen(target_set))
		{
			free(target_set);
			target_set = ft_strdup(current_set);
		}
		free(current_set);
		current = current->next;
		if (current == *src_head)
			break ;
	}
	return (target_set);
}

void	sort_stack(t_node **a_head, t_node **b_head, int size)
{
	char	*tab;

	tab = NULL;
	push(a_head, b_head, 'b');
	push(a_head, b_head, 'b');
	size -= 2;
	while (size > 3)
	{
		tab = find_cheapest_inst_set(a_head, b_head, STACK_A);
		if (!tab)
			return (display_error("sort stack failed"));
		execute_inst_set(tab, a_head, b_head);
		free(tab);
		size--;
	}
	brut_force(a_head, b_head, size, 'a');
	while (*b_head)
	{
		tab = find_cheapest_inst_set(b_head, a_head, STACK_B);
		if (!tab)
			return (display_error("sort stack failed"));
		execute_inst_set(tab, a_head, b_head);
		free(tab);
	}
	push_head_first(a_head);
}
