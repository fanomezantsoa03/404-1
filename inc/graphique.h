/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:13:17 by frajaona          #+#    #+#             */
/*   Updated: 2024/06/04 16:08:04 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIQUE_H
# define GRAPHIQUE_H
# include "structur.h"

void	init_window(t_game *game, int width, int height);
void	draw_tile(t_game *game, int x, int y, t_image img);
void	draw_map(t_game *game);
void	update_draw(t_game *game);
t_image	load_image(void *mlx, const char *path);
void	import_images(t_game *game);

#endif
