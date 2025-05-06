/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:17:32 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/06 14:21:06 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
    {
        // handle ambient parsing later
        return (1);
    }
    if (strcmp(tokens[0], "C") == 0)
    {
        // handle camera parsing later
        return (1);
    }
    if (strcmp(tokens[0], "L") == 0)
    {
        // handle light parsing later
        return (1);
    }
    return (0);
}

int parse_objects(char **tokens, t_scene *scene)
{
    if (strcmp(tokens[0], "sp") == 0)
    {
        // handle sphere parsing later
        return (1);
    }
    if (strcmp(tokens[0], "pl") == 0)
    {
        // handle plane parsing later
        return (1);
    }
    if (strcmp(tokens[0], "cy") == 0)
    {
        // handle cylinder parsing later
        return (1);
    }
    return (0);
}