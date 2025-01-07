/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_browse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:01 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 16:31:32 by alacroix         ###   ########.fr       */
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
	int		i;

	current = *head;
	i = 0;
	while (1)
	{
		if (current->value < (*target)->value
			&& ((t_node *)current->next)->value >= (*target)->value)
			break ;
		current = current->next;
		i++;
		if (current == *head)
			break ;
	}
	return (i);
}

int	reverse_target_insersion(t_node **target, t_node **head)
{
	t_node	*current;
	int		i;

	current = *head;
	i = 0;
	while (1)
	{
		if (current->value >= (*target)->value
			&& ((t_node *)current->next)->value < (*target)->value)
			break ;
		current = current->next;
		i++;
		if (current == *head)
			break ;
	}
	return (i);
}
