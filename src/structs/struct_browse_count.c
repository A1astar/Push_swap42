/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_browse_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:01 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:39:46 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	clockwise_target_search(t_node **head, t_node **target)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *head;
	while (current != *target)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	reverse_target_search(t_node **head, t_node **target)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *head;
	while (current != *target)
	{
		current = current->prev;
		i++;
	}
	return (i);
}

int	clockwise_target_insersion(t_node **target, t_node **head)
{
	t_node	*current;
	long	current_value;
	long	next_value;
	int		i;

	current = (*head);
	i = 0;
	current_value = 0;
	next_value = 0;
	while (1)
	{
		i++;
		current_value = current->value;
		next_value = ((t_node *)current->next)->value;
		if (((current_value) > (*target)->value)
			&& (next_value < (*target)->value))
			break ;
		current = current->next;
		if (current == *head)
			break ;
	}
	return (i);
}

int	reverse_target_insersion(t_node **target, t_node **head)
{
	t_node	*current;
	long	current_value;
	long	prev_value;
	int		i;

	current = (*head);
	i = 0;
	current_value = 0;
	prev_value = 0;
	while (1)
	{
		current_value = current->value;
		prev_value = ((t_node *)current->prev)->value;
		if ((current_value < (*target)->value)
			&& (prev_value > (*target)->value))
			break ;
		current = current->prev;
		i++;
		if (current == *head)
			break ;
	}
	return (i);
}
