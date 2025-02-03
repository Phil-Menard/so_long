/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:12:12 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 23:18:29 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int x, int y)
{
	if (game->player.pos_y > y)
		--game->player.pos_y;
	else if (game->player.pos_y < y)
		++game->player.pos_y;
	else if (game->player.pos_x > x)
		--game->player.pos_x;
	else if (game->player.pos_x < x)
		++game->player.pos_x;
}

void	move_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
		game->player.pos_x * IMG_HEIGHT, game->player.pos_y * IMG_WIDTH);
	update_player_pos(game, x, y);
	mlx_put_image_to_window(game->mlx, game->window, game->player.img,
		game->player.pos_x * IMG_HEIGHT, game->player.pos_y * IMG_WIDTH);
}

int	handle_input(int keysym, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if ((keysym == KEY_W || keysym == KEY_UP)
		&& game->map.full_map[y - 1][x] != WALL)
		move_player(game, game->player.pos_x, game->player.pos_y - 1);
	else if ((keysym == KEY_S || keysym == KEY_DOWN)
		&& game->map.full_map[y + 1][x] != WALL)
		move_player(game, game->player.pos_x, game->player.pos_y + 1);
	else if ((keysym == KEY_A || keysym == KEY_LEFT)
		&& game->map.full_map[y][x - 1] != WALL)
		move_player(game, game->player.pos_x - 1, game->player.pos_y);
	else if ((keysym == KEY_D || keysym == KEY_RIGHT)
		&& game->map.full_map[y][x + 1] != WALL)
		move_player(game, game->player.pos_x + 1, game->player.pos_y);
	return (0);
}
