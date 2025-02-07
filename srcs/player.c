/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:12:12 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:50:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int x, int y)
{
	game->map.full_map[game->player.pos_y][game->player.pos_x] = FLOOR;
	if (game->player.pos_y > y)
	{
		--game->player.pos_y;
		game->player.is_going_up = 1;
		game->player.is_going_down = 0;
	}
	else if (game->player.pos_y < y)
	{
		++game->player.pos_y;
		game->player.is_going_up = 0;
		game->player.is_going_down = 1;
	}
	else if (game->player.pos_x > x)
	{
		--game->player.pos_x;
		game->player.is_going_up = 0;
		game->player.is_going_down = 0;
	}
	else if (game->player.pos_x < x)
	{
		++game->player.pos_x;
		game->player.is_going_up = 0;
		game->player.is_going_down = 0;
	}
}

void	change_sprites(t_game *game, t_sprite *sprite, t_sprite *character)
{
	mlx_put_image_to_window(game->mlx, game->window, sprite->img,
		character->pos_x * IMG_HEIGHT,
		character->pos_y * IMG_WIDTH);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.full_map[y][x] != EXIT
		|| (game->map.full_map[y][x] == EXIT && game->total_coins == 0))
		update_move_counter(game);
	if (game->map.full_map[y][x] != EXIT)
	{
		change_sprites(game, &(game->floor), &(game->player));
		if (game->map.full_map[y][x] == COIN)
		{
			coins_counter(game);
			game->map.full_map[y][x] = FLOOR;
		}
		update_player_pos(game, x, y);
		game->map.full_map[game->player.pos_y][game->player.pos_x] = PLAYER;
		change_sprites(game, &(game->player), &(game->player));
	}
	else if (game->map.full_map[y][x] == EXIT && game->total_coins == 0)
	{
		change_sprites(game, &(game->floor), &(game->player));
		update_player_pos(game, x, y);
		game->map.full_map[game->player.pos_y][game->player.pos_x] = PLAYER;
		change_sprites(game, &(game->player), &(game->player));
		end_game(game);
	}
}

int	handle_input(int keysym, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (game->player.game_over == 0)
	{
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
		if (game->ennemy.is_going_up != -1)
			move_ennemy(game, game->ennemy.pos_x, game->ennemy.pos_y);
	}
	return (0);
}
