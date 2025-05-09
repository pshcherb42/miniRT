/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:58:30 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 16:50:31 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void    free_tokens(char **tokens)
{
	
}

double 	vec3_length(t_vec3 vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

int     is_valid_color_value(int value)
{
	return (value >= 0 && value <= 255);
}

int     is_valid_double(char *str)
{
	int dot_count = 0;

	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str) && *str != '.')
			return (0);
		if (*str == '.')
			dot_count++;
		if (dot_count > 1)
			return (0);
		str++;
	}
	return (1);
}