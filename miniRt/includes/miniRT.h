/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:55:51 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/16 16:16:31 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "parser.h"

typedef struct  s_light_c
{
    t_color	ambient;
	t_color	diffuse_total;
	t_light	*light;
	t_vec3	light_dir;
	double	dot;
	double	intensity;
	t_color	diffuse;
}   t_light_c;


// color_combine.c
t_color color_scale(t_color color, double factor);
t_color color_add(t_color a, t_color b);

// lightning_calculations.c
t_color	compute_lighting(t_vec3 hit_point, t_vec3 normal, t_color obj_color,
						 t_scene *scene);

#endif
