/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:56:14 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 17:19:29 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"


void show_over(t_game *game)
{
    draw_window(game, "assets/gameover.xpm", "audio/gameover.wav");
    int play_selected = 0;
    mlx_key_hook(game->win, handle_over_keypress, game);
    mlx_loop_hook(game->mlx, handle_over_keypress, &play_selected);
    mlx_loop(game->mlx);
}

void	update_position(t_game *game, int new_x, int new_y)
{
    if (new_x > game->player_x)
	    game->map->grid[new_y][new_x] = 'D';
    else if (new_x < game->player_x)
	    game->map->grid[new_y][new_x] = 'G';
    else if (new_y < game->player_y)
	    game->map->grid[new_y][new_x] = 'B';
    else
	    game->map->grid[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}

void	handle_collectible(t_game *game, int new_x, int new_y, char new_tile)
{
	if (new_tile == 'V')
	{
		 bool correct_answer = false;
        while (!correct_answer)
        {
            correct_answer = varavarana();
			if (correct_answer == false)
			{
				mlx_destroy_window(game->mlx, game->win);
				mlx_destroy_display(game->mlx);
				free_map(game->map);
				show_over(game);
			}
        }
		game->map->grid[game->player_y][game->player_x] = '0';
	}
	else
		game->map->grid[game->player_y][game->player_x] = 'O';
}

void	update_player(t_game *game, int new_x, int new_y, char new_tile)
{
	if (new_tile == 'V' || new_tile == 'O')
		handle_collectible(game, new_x, new_y, new_tile);
	else
		game->map->grid[game->player_y][game->player_x] = '0';
	update_position(game, new_x, new_y);
	check_win(game);
}

void	action_player(t_game *game, int new_x, int new_y)
{
	char	new_tile;

	if (new_x >= 0
		&& new_x < game->map->width
		&& new_y >= 0
		&& new_y < game->map->height)
	{
		new_tile = game->map->grid[new_y][new_x];
		if (new_tile != '1')
		{
			update_player(game, new_x, new_y, new_tile);
			update_draw(game);
		}
	}
}
