/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:26 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 16:33:51 by pmenard          ###   ########.fr       */
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
	int	i;
	int	j;
	int	previous;

	i = 0;
	previous = -1;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full_map[i][j] == ENNEMY)
			{
				ft_printf("column : %s\n", game->map.full_map[i]);
				game->ennemy.pos_x = j;
				game->ennemy.pos_y = i;
				if (j != previous)
					previous = move_ennemy_y_axis(game, i, j);
			}
			j++;
		}
		i++;
	}
}

/* void	move_ennemy_x_axis(t_game *game, int x, int y)
{
	if (game->ennemy.is_going_left == 1)
	{
		if (game->map.full_map[y][x - 1] != WALL
			&& game->map.full_map[y][x - 1] != EXIT)
		{
			change_sprites(game, &(game->floor), &(game->ennemy));
			--game->ennemy.pos_x;
			change_sprites(game, &(game->ennemy), &(game->ennemy));
		}
		else
			game->ennemy.is_going_left = 0;
	}
	else
	{
		if (game->map.full_map[y][x + 1] != WALL
			&& game->map.full_map[y][x - 1] != EXIT)
		{
			change_sprites(game, &(game->floor), &(game->ennemy));
			++game->ennemy.pos_x;
			change_sprites(game, &(game->ennemy), &(game->ennemy));
		}
		else
			game->ennemy.is_going_left = 1;
	}
} */