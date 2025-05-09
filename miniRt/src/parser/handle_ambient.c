/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:38:54 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 10:54:55 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

double      parse_double(char *str)
{
	return (atof(str));
}

t_color     parse_color(char *str)
{
	t_color 	color;
	
    char **values = ft_split(str, ',');
    if (!values[0] || !values[1] || !values[2])
        return (t_color){0, 0, 0};
    color.r = atoi(values[0]);
    color.g = atoi(values[1]);
    color.b = atoi(values[2]);
    free_tokens(values);
    return color;
}

int    handle_ambient(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2])
		return (0);
	scene->ambient.ratio = parse_double(tokens[1]);
	scene->ambient.color = parse_color(tokens[2]);
	return (1);
}