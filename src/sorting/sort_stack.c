/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:19:46 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/07 00:21:54 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/moves_set.h"

int	clockwise_insersion(t_node **target, t_node **head)
{
	t_node	*current;
	int		i;

	current = *head;
	i = 0;
	while (current->value < (*target)->value)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	reverse_insersion(t_node **target, t_node **head)
{
	t_node	*current;
	int		i;

	current = (*head)->prev;
	i = 1;
	while (current->value > (*target)->value)
	{
		current = current->prev;
		i++;
		if(current == (*head))
			return (i);
	}
	return (i);
}

bool	is_min_value(t_node **target, t_node **head)
{
	t_node	*current;

	current = *head;
	while (current->next != *head)
	{
		if (current->value < (*target)->value)
			return (false);
		current = current->next;
	}
	if (current->value < (*target)->value)
		return (false);
	return (true);
}

bool	is_max_value(t_node **target, t_node **head)
{
	t_node	*current;

	current = *head;
	while (current->next != *head)
	{
		if (current->value > (*target)->value)
			return (false);
		current = current->next;
	}
	if (current->value > (*target)->value)
		return (false);
	return (true);
}

char	*str_extend(char *str1, char c)
{
	char	*temp;
	char	str2[2];

	str2[0] = c;
	str2[1] = '\0';
	if(!str1)
		return (NULL);
	temp = ft_strjoin(str1, str2);
	if (!temp)
		return (free(str1), NULL);
	return (free(str1), temp);
}

void	put_instructions(char **tab, int nbr, char mov)
{
	int	i;

	i = 0;
	if(!tab || !*tab)
		return ;
	while (i < nbr)
	{
		*tab = str_extend(*tab, mov);
		if(!*tab)
			return(display_error("put instruct failed")) ;
		i++;
	}
}

void	push_head_inst(char **tab, t_node **current, t_node **a_head)
{
	int	r_moves;
	int	rr_moves;

	r_moves = clockwise_search(a_head, current);
	rr_moves = reverse_search(a_head, current);
	if (r_moves < rr_moves)
		put_instructions(tab, r_moves, RA);
	else
		put_instructions(tab, rr_moves, RRA);
}

void	target_pos_inst(char **tab, t_node **current, t_node **b_head)
{
	int	r_moves;
	int	rr_moves;

	r_moves = 0;
	rr_moves = 0;
	if (!tab)
		return ;
	if (is_max_value(current, b_head) == true)
		*tab = str_extend(*tab, RB);
	else if (is_min_value(current, b_head) == true)
		return ;
	else
	{
		r_moves = clockwise_insersion(current, b_head);
		rr_moves = reverse_insersion(current, b_head);
		if (rr_moves < r_moves)
			put_instructions(tab, rr_moves, RRB);
		else
			put_instructions(tab, r_moves, RB);
	}
}

char	*inst_set_of(t_node **current, t_node **a_head, t_node **b_head)
{
	char	*tab;

	tab = ft_calloc(1, sizeof(char));
	if (!tab)
		return (NULL);
	push_head_inst(&tab, current, a_head);
	tab = str_extend(tab, PB);
		if (!tab)
			return (NULL);
	target_pos_inst(&tab, current, b_head);
	tab = find_optimisation_to_b(tab);
	if(!tab)
		return (NULL);
	return (tab);
}

char	*find_cheapest_inst_set(t_node **a_head, t_node **b_head)
{
	t_node	*current;
	char	*current_set;
	char	*target_set;

	current = *a_head;
	current_set = NULL;
	target_set = NULL;
	while (1)
	{
		current_set = inst_set_of(&current, a_head, b_head);
		if (!current_set)
			return (free(target_set), NULL);
		if (!target_set ||ft_strlen(current_set) < ft_strlen(target_set))
		{
			free(target_set);
			target_set = ft_strdup(current_set);
		}
		free(current_set);
		current = current->next;
		if(current == *a_head)
			break ;
	}
	return (target_set);
}

void	sort_stack(t_node **a_head, t_node **b_head, int size)
{
	char	*tab;

	tab = NULL;
	push(a_head, b_head, 'b');
	push(a_head, b_head, 'b');
	size -= 2;
	while (size > 3)
	{
		tab = find_cheapest_inst_set(a_head, b_head);
		if (!tab)
			return (display_error("inst. set failed"));
		execute_inst_set(tab, a_head, b_head);
		free(tab);
		size--;
	}
	brut_force(a_head, b_head, size, 'a');
}
