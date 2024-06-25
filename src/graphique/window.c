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

void draw_window(t_game *game, char *asset, const char *audio)
{
    int win_width = 800;
    int win_height = 600;
    
    game->mlx = mlx_init();
    if (game->mlx == NULL)
    {
        printf(RED "Error" RESET "\n");
        exit(EXIT_FAILURE);
    }
    game->win = mlx_new_window(game->mlx, win_width, win_height, "Fahaleovatena");
    if (game->win == NULL)
    {
        printf(RED "Error" RESET "\n");
        exit(EXIT_FAILURE);
    }
    game->background_img = mlx_xpm_file_to_image(game->mlx, asset, &game->bg_width, &game->bg_height);
    if (game->background_img == NULL)
    {
        printf(RED "Error" RESET "\n");
        exit(EXIT_FAILURE);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->background_img, 0, 0);
    play_audio(audio);
}
