/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:56:56 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/09 17:55:48 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_head;

	a_head = NULL;
	if (argc < 2)
		return (0);
	if (create_stack(&a_head, argc, argv) == false)
		return (free_stack(&a_head), 1);
	if (stack_is_sorted(a_head))
		return (free_stack(&a_head), 0);
	dispatcher(&a_head);
	return (0);
}
