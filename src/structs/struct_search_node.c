/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_search_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:19:45 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 16:45:55 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*search_vmin_node(t_node **head)
{
	t_node	*current;
	t_node	*min;

	if(!*head)
		return (NULL);
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

t_node	*search_vmax_node(t_node **head)
{
	t_node	*current;
	t_node	*max;

	if(!*head)
		return (NULL);
	if ((*head)->next == *head)
		return (*head);
	max = *head;
	current = (*head)->next;
	while (current != *head)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

