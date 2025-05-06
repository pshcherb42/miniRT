/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:56:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/06 14:03:50 by pshcherb         ###   ########.fr       */
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

void    read_rt_file(const char *filename);
int     id_element(char **tokens, t_scene *scene); // Determines element type and routes parsing
int     convert_parts(char **tokens, t_scene *scene); // Converts strings to numbers/vectors
int     store_tokens(char **tokens, t_scene *scene);  // Allocates and saves object into scene
void    free_tokens(char **tokens);              // Frees token array

#endif 