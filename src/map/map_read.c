/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:32:03 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 16:34:13 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

static char	*read_first_line(int fd, int *width)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		*width = strlen(line) - 1;
	return (line);
}

int	read_map_dimensions(const char *filename, int *width, int *height)
{
	int		fd;
	char	*line;

	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	line = read_first_line(fd, width);
	if (!line)
	{
		close(fd);
		return (-1);
	}
	*height = 1;
	free(line);
	*height += count_lines(fd);
	close(fd);
	if (*width > 0 && *height > 0)
		return (0);
	return (-1);
}

static char	*read_next_line(int fd)
{
	return (get_next_line(fd));
}

int	read_map_lines(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		row;

	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	line = read_next_line(fd);
	row = 0;
	while (line != NULL)
	{
		strncpy(map->grid[row], line, map->width);
		map->grid[row][map->width] = '\0';
		free(line);
		row++;
		line = read_next_line(fd);
	}
	close(fd);
	if (row == map->height)
		return (0);
	return (-1);
}

t_map	*read_map(const char *filename)
{
	int		width;
	int		height;
	t_map	*map;

	if (read_map_dimensions(filename, &width, &height) == -1)
		return (NULL);
	map = create_empty_map(width, height);
	if (!map)
		return (NULL);
	if (read_map_lines(filename, map) == -1)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}