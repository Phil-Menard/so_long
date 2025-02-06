/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:26 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 17:25:32 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_tiles(t_game *game, int x, int y, int z)
{
	game->map.full_map[x][y] = FLOOR;
	game->map.full_map[z][y] = ENNEMY;
}

int	move_ennemy_y_axis(t_game *game, int x, int y)
{
	if (game->ennemy.is_going_up == 1)
	{
		if (game->map.full_map[x - 1][y] == FLOOR)
		{
			change_sprites(game, &(game->floor), &(game->ennemy));
			--game->ennemy.pos_y;
			change_sprites(game, &(game->ennemy), &(game->ennemy));
			swap_tiles(game, x, y, x - 1);
		}
		else
			game->ennemy.is_going_up = 0;
	}
	else
	{
		if (game->map.full_map[x + 1][y] == FLOOR)
		{
			change_sprites(game, &(game->floor), &(game->ennemy));
			++game->ennemy.pos_y;
			change_sprites(game, &(game->ennemy), &(game->ennemy));
			swap_tiles(game, x, y, x + 1);
		}
		else
			game->ennemy.is_going_up = 1;
	}
	return (y);
}

void	move_ennemy(t_game *game)
{
	int	x;
	int	y;

	x = game->ennemy.pos_x;
	y = game->ennemy.pos_y;
	move_ennemy_y_axis(game, y, x);

}
