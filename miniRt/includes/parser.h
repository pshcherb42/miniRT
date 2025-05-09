/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:56:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 17:20:38 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "scene.h"
# include "scene.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

// read_rt_file.c
void	read_rt_file(const char *filename);
void	process_line(char *line, t_scene *scene);

// id_element.c
int     id_element(char **tokens, t_scene *scene);
int     parse_ambient(char **tokens, t_scene *scene);
int     parse_objects(char **tokens, t_scene *scene);

// convert_ambient.c
int		handle_ambient(char **tokens, t_scene *scene);
int		handle_camera(char **tokens, t_scene *scene);
int		handle_light(char **tokens, t_scene *scene);
// convert_objects.c
int		handle_sphere(char **tokens, t_scene *scene);
int		handle_plane(char **tokens, t_scene *scene);
int		handle_cylinder(char **tokens, t_scene *scene);

// parsing_utils.c
void	free_tokens(char **tokens);
int		is_valid_double(char *str);
int     is_valid_color_value(int value);
double 	vec3_length(t_vec3 vec);

#endif 