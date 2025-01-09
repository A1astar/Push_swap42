/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:10:40 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/09 18:47:07 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	size_of_two(t_node **a_head, t_node *next, char stack)
{
	if ((*a_head)->value > next->value)
		swap(a_head, stack);
	else
		return ;
}

static void	size_of_three(t_node **a, t_node *b, t_node *c, char stack)
{
	long	v0;
	long	v1;
	long	v2;

	v0 = (*a)->value;
	v1 = b->value;
	v2 = c->value;
	if (v0 > v1 && v1 < v2 && v2 > v0)
		swap(a, stack);
	else if (v0 > v1 && v1 < v2 && v2 < v0)
		rotate(&b, stack);
	else if (v0 > v1 && v1 > v2 && v2 < v0)
	{
		swap(a, stack);
		reverse_rotate(a, stack);
	}
	else if (v0 < v1 && v1 > v2 && v2 > v0)
	{
		swap(a, stack);
		rotate(a, stack);
	}
	else if (v0 < v1 && v1 > v2 && v2 < v0)
		reverse_rotate(a, stack);
	else
		return ;
}

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
	size_of_three(src_head, ((t_node *)(*dst_head))->next,
		((t_node *)(*dst_head))->prev, stack);
	while (i > 0)
	{
		push(dst_head, src_head, stack);
		i--;
	}
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
