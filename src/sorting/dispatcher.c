/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:19:23 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:38:38 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dispatcher(t_node **a_head)
{
	int		size;
	t_node	*b_head;

	size = ((t_node *)(*a_head)->prev)->index + 1;
	b_head = NULL;
	if (size < 6)
		brut_force(a_head, &b_head, size, 'a');
	else
		sort_stack(a_head, &b_head, size);
	free_stack(a_head);
	free_stack(&b_head);
}
