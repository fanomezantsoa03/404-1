/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:22:11 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/15 11:31:55 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

static t_map	*create_map_struct(int width, int height)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		printf(RED "Error" RESET "\n");
		return (NULL);
	}
	map->width = width;
	map->height = height;
	return (map);
}

static char	**create_map_grid(int height)
{
	char	**grid;

	grid = (char **)malloc(sizeof(char *) * height);
	if (!grid)
	{
		printf(RED "Error" RESET "\n");
		return (NULL);
	}
	return (grid);
}

static int	create_grid_lines(char **grid, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		grid[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!grid[i])
		{
			printf(RED "Error" RESET "\n");
			while (i > 0)
				free(grid[--i]);
			return (-1);
		}
		i++;
	}
	return (0);
}

t_map	*create_empty_map(int width, int height)
{
	t_map	*map;

	map = create_map_struct(width, height);
	if (!map)
		return (NULL);
	map->grid = create_map_grid(height);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	if (create_grid_lines(map->grid, width, height) == -1)
	{
		free(map->grid);
		free(map);
		return (NULL);
	}
	return (map);
}
