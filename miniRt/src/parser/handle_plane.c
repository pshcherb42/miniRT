/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:42:18 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 18:12:30 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	handle_plane(char **tokens, t_scene *scene)
{
	t_plane	*plane;

	if (!tokens[1] || !tokens[2] || !tokens[3])
	{
		ft_printf("Error: Missing parameters for Plane");
		return (0);
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		ft_printf("Error: Memory allocation failed for Plane");
		return (0);
	}
	plane->point = parse_vec3(tokens[1]);
	plane->normal = parse_vec3(tokens[2]);
	plane->color = parse_color(tokens[3]);
	if (fabs(vec3_length(plane->normal) - 1.0) > 0.001)
	{
		ft_printf("Error: Plane normal vector is not normalized\n");
		free(plane);
		return (0);
	}
	plane->next = scene->planes;
	scene->planes = plane;
	return (1);
}
