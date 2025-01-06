/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:10:40 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/02 16:39:28 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_min(t_node **src_head, t_node **dst_head, int size, char stack)
{
	t_node	*v_min;
	char	other;
	int		i;

	if (stack == 'a')
		other = 'b';
	else
		other = 'a';
	i = 0;
	v_min = NULL;
	while ((size - i) > 3)
	{
		v_min = search_vmin_node(src_head);
		put_vmin_at_head(src_head, &v_min);
		push(src_head, dst_head, other);
		i++;
	}
	brut_force(src_head, dst_head, size, stack);
	while (i)
	{
		push(dst_head, src_head, stack);
		i--;
	}
}

static void	size_of_two(t_node **a_head, t_node *next, char stack)
{
	if ((*a_head)->value > next->value)
		swap(a_head, stack);
	else
		return ;
}
static void	size_of_three(t_node **a_head, t_node *middle, t_node *last,
		char stack)
{
	long	v0;
	long	v1;
	long	v2;

	v0 = (*a_head)->value;
	v1 = middle->value;
	v2 = last->value;
	if (v0 > v1 && v1 < v2 && v2 > v0)
		swap(a_head, stack);
	else if (v0 > v1 && v1 < v2 && v2 < v0)
		rotate(a_head, stack);
	else if (v0 > v1 && v1 > v2 && v2 < v0)
	{
		swap(a_head, stack);
		reverse_rotate(a_head, stack);
	}
	else if (v0 < v1 && v1 > v2 && v2 > v0)
	{
		swap(a_head, stack);\
		rotate(a_head, stack);
	}
	else if (v0 < v1 && v1 > v2 && v2 < v0)
		reverse_rotate(a_head, stack);
	else
		return ;
}

void	brut_force(t_node **a_head, t_node **b_head, int size, char stack)
{
	if (size == 1)
		return ;
	else if (size == 2)
		size_of_two(a_head, (*a_head)->next, stack);
	else if (size == 3)
		size_of_three(a_head, (*a_head)->next, (*a_head)->prev, stack);
	else
		push_min(a_head, b_head, size, stack);
}
