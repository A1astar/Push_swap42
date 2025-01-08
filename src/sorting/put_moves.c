/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:50 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/08 15:39:10 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves_set.h"
#include "../includes/push_swap.h"

char	*put_single_inst(char *str1, char inst)
{
	char	*temp;
	char	str2[2];

	str2[0] = inst;
	str2[1] = '\0';
	if (!str1)
		return (NULL);
	temp = ft_strjoin(str1, str2);
	if (!temp)
		return (free(str1), NULL);
	return (free(str1), temp);
}

void	put_multi_inst(char **tab, int nbr, char inst)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (i < nbr)
	{
		*tab = put_single_inst(*tab, inst);
		if (!*tab)
			return (display_error("put instruct failed"));
		i++;
	}
}
