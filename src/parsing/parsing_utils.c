/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:29:47 by alacroix          #+#    #+#             */
/*   Updated: 2025/01/06 23:43:15 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	num_is_int(long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (false);
	return (true);
}

bool	onlyspace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	is_a_number(char *str)
{
	size_t	i;

	i = 0;
	if(str[i] == '-')
		i++;
	if(str[i] == '\0')
		return(false);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		i++;
	}
	return (true);
}

