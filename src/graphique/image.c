/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:31:28 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:36 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

t_image	load_image(void *mlx, const char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, (char *)path, &img.width, &img.height);
	if (img.img == NULL)
	{
		printf(RED "Error = %s" RESET "\n", path);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	import_images(t_game *game)
{
	game->wall = load_image(game->mlx, "assets/1.xpm");
	game->collectible = load_image(game->mlx, "assets/V.xpm");
	game->exit = load_image(game->mlx, "assets/E.xpm");
	game->player = load_image(game->mlx, "assets/P.xpm");
	game->empty = load_image(game->mlx, "assets/0.xpm");
	game->collected = load_image(game->mlx, "assets/O.xpm");
	game->open = load_image(game->mlx, "assets/W.xpm");
	game->left = load_image(game->mlx, "assets/G.xpm");
	game->right = load_image(game->mlx, "assets/D.xpm");
	game->down = load_image(game->mlx, "assets/B.xpm");
}
