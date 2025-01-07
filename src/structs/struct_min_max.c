/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:45:22 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 19:30:15 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_min_value(t_node **target, t_node **head)
{
	t_node	*current;

	current = *head;
	while (current->next != *head)
	{
		if (current->value < (*target)->value)
			return (false);
		current = current->next;
	}
	if (current->value < (*target)->value)
		return (false);
	return (true);
}

bool	is_max_value(t_node **target, t_node **head)
{
	t_node	*current;

	current = *head;
	while (current->next != *head)
	{
		if (current->value > (*target)->value)
			return (false);
		current = current->next;
	}
	if (current->value > (*target)->value)
		return (false);
	return (true);
}
