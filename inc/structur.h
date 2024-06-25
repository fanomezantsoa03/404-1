/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:11:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/11 11:14:12 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTUR_H
# define STRUCTUR_H

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}			t_map;

typedef struct s_directions
{
	int			*dr;
	int			*dc;
}				t_directions;

typedef struct s_explore_params
{
	t_map			*map;
	int				row;
	int				col;
	bool			**visited;
	t_directions	*dirs;
}					t_explore_params;

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_image	wall;
	t_image	collectible;
	t_image	exit;
	t_image	open;
	t_image	player;
	t_image	empty;
	t_image	collected;
	t_image	left;
	t_image	right;
	t_image	down;
	t_map	*map;
	int		player_x;
	int		player_y;
	int		move_count;
	void	*background_img;
    int		bg_width;
    int		bg_height;
}			t_game;

#endif
