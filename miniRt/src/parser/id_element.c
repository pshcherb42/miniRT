/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:17:32 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 10:11:16 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/scene.h"

int     id_element(char **tokens, t_scene *scene)
{
    if (!tokens || !tokens[0])
        return (0);
    if (parse_ambient(tokens, scene))
        return (1);
    if (parse_objects(tokens, scene))
        return (1);
    return (0);
}

int parse_ambient(char **tokens, t_scene *scene)
{
    if (strcmp(tokens[0], "A") == 0)
        return (handle_ambient(tokens, scene));
    if (strcmp(tokens[0], "C") == 0)
        return (handle_camera(tokens, scene));
    if (strcmp(tokens[0], "L") == 0)
        return (handle_light(tokens, scene));
    return (0);
}

int parse_objects(char **tokens, t_scene *scene)
{
    if (strcmp(tokens[0], "sp") == 0)
        return (handle_sphere(tokens, scene));
    if (strcmp(tokens[0], "pl") == 0)
        return (handle_plane(tokens, scene));
    if (strcmp(tokens[0], "cy") == 0)
        return (handle_cylinder(tokens, scene));
    return (0);
}