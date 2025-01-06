/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:56:56 by alacroix          #+#    #+#             */
/*   Updated: 2024/12/24 15:50:47 by alacroix         ###   ########.fr       */
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
	dispatcher(&a_head);
}
