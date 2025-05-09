/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:56:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 10:12:24 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "scene.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// read_rt_file.c
void    read_rt_file(const char *filename);
void    process_line(char *line, t_scene *scene);

// id_element.c
int     id_element(char **tokens, t_scene *scene);
int     parse_ambient(char **tokens, t_scene *scene);
int     parse_objects(char **tokens, t_scene *scene);

// convert_ambient.c
int    handle_ambient(char **tokens, t_scene *scene);
int    handle_camera(char **tokens, t_scene *scene);
int    handle_light(char **tokens, t_scene *scene);
// convert_objects.c
int    handle_sphere(char **tokens, t_scene *scene);
int    handle_plane(char **tokens, t_scene *scene);
int    handle_cylinder(char **tokens, t_scene *scene);

int     store_tokens(char **tokens, t_scene *scene);  // Allocates and saves object into scene
void    free_tokens(char **tokens);



#endif 