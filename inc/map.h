/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:39:52 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 11:21:36 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "structur.h"

void	free_map(t_map *map);
t_map	*create_empty_map(int width, int height);
int		open_file(const char *filename);
int		count_lines(int fd);
int		read_map_dimensions(const char *file, int *width, int *height);
int		read_map_lines(const char *file, t_map *map);
t_map	*read_map(const char *filename);
void	maps(t_game *game, char *path);

#endif
