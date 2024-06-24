/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fahaleovantena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:04:40 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/24 10:04:42 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fahaleovantena.h"

int	main(int argc, char **argv)
{
	t_game	game;
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
	return (0);
}
