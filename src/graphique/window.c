/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:00 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/04 15:53:18 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

void	init_window(t_game *game, int width, int height)
{
	int	w;
	int	h;

	game->win_width = game->map->width * width;
	game->win_height = game->map->height * height;
	game->mlx = mlx_init();
	w = game->win_width;
	h = game->win_height;
	if (game->mlx == NULL)
	{
		printf(RED "Error" RESET "\n");
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, w, h, "Fahaleovantena");
	if (game->win == NULL)
	{
		printf(RED "Error" RESET "\n");
		free_map(game->map);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
}
