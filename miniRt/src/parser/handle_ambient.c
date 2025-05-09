/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:38:54 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 16:35:07 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

double      parse_double(char *str)
{
    if (!is_valid_double(str))
    {
        ft_printf("Error: Invalid double value: %s\n", str);
        return (0);
    }
	return (ft_atof(str));
}

t_color     parse_color(char *str)
{
	t_color 	color;
    char        **values;
	
    values = ft_split(str, ',');
    if (!values[0] || !values[1] || !values[2])
    {
        ft_printf("Error: Invalid color format: %s\n", str);
        free_tokens(values);
        return ((t_color){0, 0, 0});
    }
    color.r = ft_atoi(values[0]);
    color.g = ft_atoi(values[1]);
    color.b = ft_atoi(values[2]);
    if (!is_valid_color_value(color.r) || !is_valid_color_value(color.g)
        || !is_valid_color_value(color.b))
    {
        ft_printf("Error: Color values out of range (0-255): %s\n", str);
        color = (t_color){0, 0, 0};
    }
    free_tokens(values);
    return (color);
}

int    handle_ambient(char **tokens, t_scene *scene)
{
    double  ratio;
    t_color color;
    
	if (!tokens[1] || !tokens[2])
	{
        ft_printf("Error: Missing parameters for Ambient light\n");
        return (0);
    }
	ratio = parse_double(tokens[1]);
    if (ratio < 0.0 || ratio > 1.0)
    {
        ft_printf("Error: Ambient light ratio out of range [0.0, 1.0]: %f\n", ratio);
        return (0);
    }
    color = parse_color(tokens[2]);
    if (color.r == 0 && color.g == 0 && color.b == 0)
    {
        ft_printf("Error: Failed to parse color for Ambient light\n");
        return (0);
    }
    scene->ambient.ratio = ratio;
	scene->ambient.color = color;
	return (1);
}