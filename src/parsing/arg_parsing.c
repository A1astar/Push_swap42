/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:04:47 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/09 18:15:49 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	skip_empty(int argc, char **argv, int *index)
{
	while (ft_strlen(argv[*index]) == 0 && onlyspace(argv[*index]) == true)
	{
		(*index)++;
		if (*index == argc)
			return (false);
	}
	(*index)++;
	return (true);
}

static bool	put_args(t_node **head, char **av, int *arg_i)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[*arg_i])
	{
		temp = ft_split(av[*arg_i], ' ');
		if (!temp)
			return (display_error("split failed"), false);
		while (temp[i])
		{
			if (lst_maker(head, temp[i], j) == false)
				return (ft_free_tab((void **)temp), false);
			i++;
			j++;
		}
		i = 0;
		ft_free_tab((void **)temp);
		(*arg_i)++;
	}
	return (true);
}

static bool	stack_is_valid(t_node *head)
{
	t_node	*current_i;
	t_node	*current_j;

	if (head->next == head)
		return (true);
	current_i = head;
	current_j = head->next;
	while (current_i->next != head)
	{
		current_j = current_i->next;
		while (current_j != head)
		{
			if (current_i->value == current_j->value)
				return (false);
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	return (true);
}

bool	create_stack(t_node **head, int argc, char **argv)
{
	int	arg_index;

	arg_index = 0;
	if (skip_empty(argc, argv, &arg_index) == false)
		return (display_error("empty arg(s)"), false);
	if (put_args(head, argv, &arg_index) == false)
		return (false);
	if (!*head)
		return (false);
	if (stack_is_valid(*head) == false)
		return (display_error("duplicate number found"), false);
	return (true);
}
