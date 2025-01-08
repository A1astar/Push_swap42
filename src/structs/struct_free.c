/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:04:48 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:39:24 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node **head)
{
	t_node	*temp;
	t_node	*next;
	t_node	*head_ptr;

	if (!head || !*head)
		return ;
	temp = *head;
	head_ptr = *head;
	while (temp->next != head_ptr)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	*head = NULL;
}
