/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:17:25 by frajaona          #+#    #+#             */
/*   Updated: 2024/05/25 09:50:48 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

void	draw_tile(t_game *game, int x, int y, t_image img)
{
	int	width;
	int	height;

	width = x * img.width;
	height = y * img.height;
	mlx_put_image_to_window(game->mlx, game->win, img.img, width, height);
}

static void	checker(t_game *game, int y, int x)
{
	if (game->map->grid[y][x] == '1')
		draw_tile(game, x, y, game->wall);
	else if (game->map->grid[y][x] == '0')
		draw_tile(game, x, y, game->empty);
	else if (game->map->grid[y][x] == 'V')
		draw_tile(game, x, y, game->collectible);
	else if (game->map->grid[y][x] == 'O')
		draw_tile(game, x, y, game->collected);
	else if (game->map->grid[y][x] == 'E')
		draw_tile(game, x, y, game->exit);
	else if (game->map->grid[y][x] == 'W')
		draw_tile(game, x, y, game->open);
	else if (game->map->grid[y][x] == 'P')
		draw_tile(game, x, y, game->player);
	else if (game->map->grid[y][x] == 'G')
		draw_tile(game, x, y, game->left);
	else if (game->map->grid[y][x] == 'D')
		draw_tile(game, x, y, game->right);
	else if (game->map->grid[y][x] == 'B')
		draw_tile(game, x, y, game->down);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			checker(game, y, x);
			x++;
		}
		y++;
	}
}

void	update_draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}
