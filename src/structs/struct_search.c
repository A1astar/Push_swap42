/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:19:45 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/06 23:56:46 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	search_vmin(t_node **a_head)
{
	t_node	*current;
	t_node	*min;

	if ((*a_head)->next == *a_head)
		return ((*a_head)->value);
	min = (*a_head);
	current = (*a_head)->next;
	while (current != (*a_head))
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min->value);
}

long	search_vmax(t_node **a_head)
{
	t_node	*current;
	t_node	*max;

	if ((*a_head)->next == *a_head)
		return ((*a_head)->value);
	max = (*a_head);
	current = (*a_head)->next;
	while (current != (*a_head))
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max->value);
}
t_node	*search_vmin_node(t_node **head)
{
	t_node	*current;
	t_node	*min;

	if ((*head)->next == *head)
		return (*head);
	min = *head;
	current = (*head)->next;
	while (current != *head)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
int	clockwise_search(t_node **a_head, t_node **target)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *a_head;
	while (current != *target)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	reverse_search(t_node **a_head, t_node **target)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *a_head;
	while (current != *target)
	{
		current = current->prev;
		i++;
	}
	return (i);
}
