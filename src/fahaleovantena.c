/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fahaleovantena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:04:40 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/25 08:33:55 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fahaleovantena.h"

int start_game = 0;
int current_selection = 0;
int handle_menu_keypress(int keycode, t_game *game);

int handle_menu_keypress(int keycode, t_game *game)
{
    if (keycode == 109)
    {
        mlx_destroy_window(game->mlx, game->win);
		start_game = 1;
        return 1;
    }
    else if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return 0;
}

void show_menu(t_game *game)
{
    draw_window(game, "assets/menu.xpm", "audio/menu.wav");
    int play_selected = 0;
    mlx_key_hook(game->win, handle_menu_keypress, game);
    mlx_loop_hook(game->mlx, handle_menu_keypress, &play_selected);
    mlx_loop(game->mlx);
}



int	main(int argc, char **argv)
{
	t_game	game;
	show_menu(&game);
	if (start_game)
    {
		maps(&game, "map/map.ber");
		game.mlx = mlx_init();
		if (game.mlx == NULL)
		{
			printf(RED "Error" RESET "\n");
			free_map(game.map);
			exit(EXIT_FAILURE);
		}
		import_images(&game);
		init_window(&game, game.wall.width, game.wall.height);
		draw_map(&game);
		mlx_key_hook(game.win, handle_keypress, &game);
		mlx_hook(game.win, 17, 1L << 0, exite_x, &game);
		mlx_loop(game.mlx);
		free_map(game.map);
	}
	return (0);
}
