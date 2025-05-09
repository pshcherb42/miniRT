/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:21:32 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 17:38:16 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	handle_sphere(char **tokens, t_scene *scene)
{
	t_sphere	*sphere;

	if (!tokens[1] || !tokens[2] || !tokens[3])
	{
		ft_printf("Error: Missing parameters for Sphere\n");
		return (0);
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		ft_printf("Error: Memory allocation failed for Sphere\n");
		return (0);
	}
	sphere->center = parse_vec3(tokens[1]);
	sphere->radius = parse_double(tokens[2]) / 2.0;
	sphere->color = parse_color(tokens[3]);
	if (sphere->radius <= 0.0)
	{
		ft_printf("Error: Invalid diameter: %f\n", sphere->radius * 2);
		free(sphere);
		return (0);
	}
	sphere->next = scene->spheres;
	scene->spheres = sphere;
	return (1);
}
