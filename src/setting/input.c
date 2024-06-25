/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:45:18 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 18:29:08 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fahaleovantena.h"

int	exite_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	exit_esc(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(EXIT_SUCCESS);
}

static void	move_player(t_game *game, int keysym)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keysym == 119)
		new_y--;
	else if (keysym == 97)
		new_x--;
	else if (keysym == 115)
		new_y++;
	else if (keysym == 100)
		new_x++;
	if (new_x != game->player_x || new_y != game->player_y)
		action_player(game, new_x, new_y);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
	{
		move_player(game, keysym);
	}
	else if (keysym == 65307)
	{
		exit_esc(game);
	}
	return (0);
}

int handle_over_keypress(int keycode, t_game *game)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return 0;
}

int handle_win_keypress(int keycode, t_game *game)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return 0;
}
