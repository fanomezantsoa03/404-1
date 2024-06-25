/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:02:27 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 14:19:18 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

void show_win(t_game *game)
{
    draw_window(game, "assets/win.xpm", "audio/win.wav");
    int play_selected = 0;
    mlx_key_hook(game->win, handle_win_keypress, game);
    mlx_loop_hook(game->mlx, handle_win_keypress, &play_selected);
    mlx_loop(game->mlx);
}


int	check_win_condition(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'W')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_win(t_game *game)
{
	if (check_win_condition(game->map))
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free_map(game->map);
		show_win(game);
	}
}
