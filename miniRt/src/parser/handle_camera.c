/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:24:37 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 16:49:42 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int    handle_camera(char **tokens, t_scene *scene)
{
     if (!tokens[1] || !tokens[2] || !tokens[3])
    {
        ft_printf("Error: Missing parameters for Camera\n");
        return (0);
    }
    scene->camera.position = parse_vec3(tokens[1]);
    scene->camera.orientation = parse_vec3(tokens[2]);
    if (fabs(vec3_length(scene->camera.orientation) - 1.0) > 0.001)
    {
        ft_printf("Error: Camera orientation vector is not normalized");
        return (0);
    }
    scene->camera.fov = parse_double(tokens[3]);
    if (scene->camera.fov <= 0 || scene->camera.fov >= 180)
    {
        ft_printf("Error: Camera FOV out of range [0, 180]: %f\n",
                    scene->camera.fov);
        return (0);
    }
    return (1);
}