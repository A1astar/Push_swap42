/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:16:56 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:31:55 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **src_head, t_node **dst_head, char stack)
{
	t_node	*temp;

	if (!src_head || !(*src_head))
		return ;
	temp = *src_head;
	lst_remove_node(src_head);
	lst_new_head(dst_head, temp);
	index_update(src_head);
	index_update(dst_head);
	if (stack != '*')
		ft_printf("p%c\n", stack);
}

void	rotate(t_node **head, char stack)
{
	if (!head || !(*head) || (*head)->next == (*head))
		return ;
	*head = (*head)->next;
	index_update(head);
	if (stack != '*')
		ft_printf("r%c\n", stack);
}

void	rotate_all(t_node **a_head, t_node **b_head, char stack)
{
	rotate(a_head, '*');
	rotate(b_head, '*');
	if (stack != '*')
		ft_printf("rr\n");
}
