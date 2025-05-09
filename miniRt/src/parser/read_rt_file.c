/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:22:53 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 10:16:44 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void read_rt_file(const char *filename, t_scene *scene)
{
    int fd;
    char *line;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        process_line(line, scene);
        free(line);
    }
    close(fd);
}

void    process_line(char *line, t_scene *scene)
{
    char **tokens;

    if (!line || !*line || line[0] == '\n')
        return;
    tokens = ft_split(line, " ");
    if (!tokens)
        return;
    if (!id_element(tokens, scene))
    {
        fprintf(stderr, "Error: unknown or invalid element in line: %s\n", line);
        free_tokens(tokens);
        return;
    }
    /*if (!convert_parts(tokens, scene))
    {
        fprintf(stderr, "Error: failed to convert values in line: %s\n", line);
        free_tokens(tokens);
        return;
    }
    if (!store_tokens(tokens, scene))
        fprintf(stderr, "Error: failed to store element from line: %s\n", line);*/
    free_tokens(tokens);
}
