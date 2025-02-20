/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:17:01 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:32:04 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_node **head, char stack)
{
	if (!head || !(*head) || (*head)->prev == (*head))
		return ;
	*head = (*head)->prev;
	index_update(head);
	if (stack != '*')
		ft_printf("rr%c\n", stack);
}

void	reverse_rotate_all(t_node **a_head, t_node **b_head, char stack)
{
	reverse_rotate(a_head, '*');
	reverse_rotate(b_head, '*');
	if (stack != '*')
		ft_printf("rrr\n");
}
