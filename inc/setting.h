/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:49:09 by frajaona          #+#    #+#             */
/*   Updated: 2024/05/24 12:12:36 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H
# include "structur.h"

int		exite_x(t_game *game);
void	check_exit(t_game *game);
void	check_win(t_game *game);
int		check_win_condition(t_map *map);
void	update_player(t_game *game, int new_x, int new_y, char new_tile);
void	action_player(t_game *game, int new_x, int new_y);
int		handle_keypress(int keysym, t_game *game);

#endif
