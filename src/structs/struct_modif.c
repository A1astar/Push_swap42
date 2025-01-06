/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:34:15 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/06 23:53:47 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lst_remove_node(t_node **head)
{
	t_node	*src_last;

	if (!head || !(*head))
		return ;
	if ((*head)->next == *head)
		*head = NULL;
	else
	{
		src_last = (*head)->prev;
		(*head) = (*head)->next;
		src_last->next = *head;
		(*head)->prev = src_last;
	}
}

void	lst_new_head(t_node **head, t_node *temp)
{
	t_node	*dst_last;

	if (!temp)
		return ;
	if (!head || !(*head))
	{
		*head = temp;
		(*head)->prev = temp;
		(*head)->next = temp;
	}
	else
	{
		dst_last = (*head)->prev;
		temp->prev = dst_last;
		temp->next = *head;
		dst_last->next = temp;
		(*head)->prev = temp;
		*head = temp;
	}
}

void	index_update(t_node **head)
{
	int		i;
	t_node	*temp;

	i = 0;
	if (!(*head) || !head)
		return ;
	temp = *head;
	while (temp->next != *head)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	temp->index = i;
}

void	put_vmin_at_head(t_node **head, t_node **v_min)
{
	if (clockwise_search(head, v_min) <= reverse_search(head, v_min))
	{
		while (*head != *v_min)
			rotate(head, 'a');
	}
	else
	{
		while (*head != *v_min)
			reverse_rotate(head, 'a');
	}
}
