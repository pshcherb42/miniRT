/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:59:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 17:12:28 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	handle_light(char **tokens, t_scene *scene)
{
	if (!tokens[1] || !tokens[2] || !tokens[3])
	{
		ft_printf("Error: Missing parameters for Light\n");
		return (0);
	}
	light = malloc(sizeof(t_light));
	if (!light)
	{
		ft_printf("Error: Memory allocation failed for Light\n");
		return (0);
	}
	light->position = parse_vec3(tokens[1]);
	light->brightness = parse_double(tokens[2]);
	light->color = parse_color(tokens[3]);
	if (light->brightness < 0.0 || light->brightness > 1.0)
	{
		ft_printf("Error: Light brightness out of range [0.0, 1.0]: %f\n",
			light->brightness);
		free(light);
		return (0);
	}
	light->next = scene->lights;
	scene->lights = light;
	return (1);
}
