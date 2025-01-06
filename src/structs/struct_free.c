/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:04:48 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/06 23:55:53 by alacroix         ###   ########.fr       */
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

