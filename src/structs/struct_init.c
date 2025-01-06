/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:36 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 00:32:32 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	create_head_node(t_node **head, char *str)
{
	long	num;

	num = ft_atol(str);
	if (num_is_int(num) == false)
		return (display_error("num is not an int"), false);
	(*head) = malloc(sizeof(t_node));
	if (!head)
		return (display_error("Head node creation failed"), false);
	(*head)->value = num;
	(*head)->index = 0;
	(*head)->prev = (*head);
	(*head)->next = (*head);
	return (true);
}

bool	new_node(t_node **head, char *str, int i)
{
	t_node	*last;
	t_node	*new;
	long	num;

	num = ft_atol(str);
	if (num_is_int(num) == false)
		return (display_error("num is not an int"), false);
	if (!(*head))
		return (display_error("Head node not init"), false);
	last = (*head)->prev;
	new = malloc(sizeof(t_node));
	if (!new)
		return (display_error("New node cretion failed"), false);
	new->value = num;
	new->index = i;
	new->prev = last;
	new->next = (*head);
	last->next = new;
	(*head)->prev = new;
	return (true);
}

bool	lst_maker(t_node **head, char *str, int i)
{
	if (is_a_number(str) == false)
		return (display_error("wrong arg. type"), false);
	if (!(*head))
	{
		if (create_head_node(head, str) == false)
			return (false);
	}
	else
	{
		if (new_node(head, str, i) == false)
			return (false);
	}
	return (true);
}
