/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:56:28 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/15 11:16:09 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "parser.h"
# include <stdbool.h>

typedef struct	s_ray {
	t_vec3	origin;
	t_vec3	direction;
} t_ray;

typedef struct s_sphere_i
{
	t_vec3  oc;
    double  a;
    double  b;
    double  c;
    double 	discriminant;
    double 	sqrt_d;
    double 	t0;
    double 	t1;
	bool	valid;
} t_sphere_i;


// vec3_add_sub.c
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);

// vec3_dot_cross.c
double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

// vec3_scalar_normal.c
t_vec3	vec3_scale(t_vec3 v, double scalar);
t_vec3	vec3_normalize(t_vec3 v);

// ray.c
t_ray	create_ray(t_vec3 origin, t_vec3 direction);
t_vec3	ray_at(t_ray ray, double t);

#endif