/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:14:03 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/04 15:48:26 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(RED "Error" RESET "\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	free_map(t_map *map)
{
	int	i;
	if (map == NULL)
        return;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i] != NULL)
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int	count_lines(int fd)
{
	char	*line;
	int		height;

	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	return (height);
}