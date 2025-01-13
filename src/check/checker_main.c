/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:04:51 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/13 17:32:15 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

char	inst(char *line)
{
	if (!ft_strncmp("pa\n", line, ft_strlen(line)))
		return (PA);
	else if (!ft_strncmp("pb\n", line, ft_strlen(line)))
		return (PB);
	else if (!ft_strncmp("ra\n", line, ft_strlen(line)))
		return (RA);
	else if (!ft_strncmp("rb\n", line, ft_strlen(line)))
		return (RB);
	else if (!ft_strncmp("rra\n", line, ft_strlen(line)))
		return (RRA);
	else if (!ft_strncmp("rrb\n", line, ft_strlen(line)))
		return (RRB);
	else if (!ft_strncmp("rr\n", line, ft_strlen(line)))
		return (RR);
	else if (!ft_strncmp("rrr\n", line, ft_strlen(line)))
		return (RRR);
	else if (!ft_strncmp("sa\n", line, ft_strlen(line)))
		return (SA);
	else if (!ft_strncmp("sb\n", line, ft_strlen(line)))
		return (SB);
	else if (!ft_strncmp("ss\n", line, ft_strlen(line)))
		return (SS);
	else
		return (SUP);
}

static char	*join(char *set, char *line)
{
	char	str[2];
	char	*temp;

	str[0] = inst(line);
	if (str[0] == SUP)
		return (free(set), NULL);
	str[1] = '\0';
	temp = ft_strjoin(set, str);
	free(set);
	return (temp);
}

static char	*put_instructions(int fd)
{
	char	*line;
	char	*set;

	line = NULL;
	set = ft_calloc(1, 1);
	if (!set)
		return (NULL);
	while (fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		set = join(set, line);
		if (!set)
			return (free(line), NULL);
		free(line);
	}
	return (set);
}

int	main(int argc, char **argv)
{
	t_node	*a_head;
	t_node	*b_head;
	char	*instructions_set;

	a_head = NULL;
	b_head = NULL;
	instructions_set = NULL;
	if (argc < 2)
		return (0);
	if (!create_stack(&a_head, argc, argv))
		return (free_stack(&a_head), 1);
	if (stack_is_sorted(a_head))
		return (free_stack(&a_head), 0);
	instructions_set = put_instructions(STDIN_FILENO);
	if (!instructions_set)
		return (free_stack(&a_head), free_stack(&b_head),
			free(instructions_set), display_error("wrong instructions"), 1);
	check_execute_inst(&a_head, &b_head, instructions_set);
	if (!stack_is_sorted(a_head) || b_head)
		return (free_stack(&a_head), free_stack(&b_head),
			free(instructions_set), ft_printf("KO\n"), 0);
	return (free(instructions_set), free_stack(&a_head), ft_printf("OK\n"), 0);
}
