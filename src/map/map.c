/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:49:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/19 17:05:22 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

void	updated_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	maps(t_game *game, char *path)
{
	int	validation_result;

	game->map = read_map(path);
	if (game->map == NULL)
	{
		printf(RED "Error" RESET "\n");
		exit(EXIT_FAILURE);
	}
	updated_map(game);
}