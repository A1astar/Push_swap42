/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:15:20 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/14 17:56:10 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_is_sorted(t_node *a_head)
{
	t_node	*current;

	if (!a_head)
		return (false);
	current = a_head;
	while (current->next != a_head)
	{
		if (current->value > ((t_node *)(current)->next)->value)
			return (false);
		current = current->next;
	}
	return (true);
}
