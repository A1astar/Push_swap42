/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:12:40 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:32:13 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **head, char stack)
{
	long	temp;
	t_node	*next;

	if (!head || !(*head) || !(*head)->next)
		return ;
	temp = (*head)->value;
	next = (*head)->next;
	(*head)->value = next->value;
	next->value = temp;
	if (stack != '*')
		ft_printf("s%c\n", stack);
}

void	swap_all(t_node **a_head, t_node **b_head, char stack)
{
	swap(a_head, '*');
	swap(b_head, '*');
	if (stack != '*')
		ft_printf("ss\n");
}
