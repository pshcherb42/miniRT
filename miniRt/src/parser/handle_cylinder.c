/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:09:03 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 18:23:53 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	error_handling(t_cylinder *cylinder)
{
	if (fabs(vec3_length(cylinder->direction) - 1.0) > 0.001)
	{
		ft_printf("Error: Cylinder direction vector is not normalized\n");
		free(cylinder);
		return (0);
	}
	if (cylinder->radius <= 0.0 || cylinder->height <= 0.0)
	{
		ft_printf("Error: Cylinder dimensions are invalid\n");
		free(cylinder);
		return (0);
	}
	return (1);
}

int	handle_cylinder(char **tokens, t_scene *scene)
{
	t_cylinder	*cylinder;

	if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5])
	{
		ft_printf("Error: Missing parameters for Cylinder\n");
		return (0);
	}
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
	{
		ft_printf("Error: Memory allocation failed for Cylinder\n");
		return (0);
	}
	cylinder->base = parse_vec3(tokens[1]);
	cylinder->direction = parse_vec3(tokens[2]);
	cylinder->radius = parse_double(tokens[3]) / 2.0;
	cylinder->height = parse_double(tokens[4]);
	cylinder->color = parse_color(tokens[5]);
	if (!error_handling(cylinder))
		return (0);
	cylinder->next = scene->cylinders;
	scene->cylinders = cylinder;
	return (1);
}
