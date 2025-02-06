/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:26 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 21:24:52 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_tiles(t_game *game, int x, int y, int z)
{
	if (game->map.full_map[z][y] == PLAYER
		|| game->map.full_map[x][y] == PLAYER)
	{
		ft_printf("Game over !\n");
		mlx_clear_window(game->mlx, game->window);
		mlx_string_put(game->mlx, game->window, (game->map.columns
				* (IMG_WIDTH / 2) - 32), ((game->map.rows)
				* ((IMG_HEIGHT / 2) + 12)) - 32, 0xFFFFFF, "GAME OVER LOOSER!");
		game->player.game_over = 1;
	}
	else
	{
		change_sprites(game, &(game->ennemy), &(game->ennemy));
		game->map.full_map[x][y] = FLOOR;
		game->map.full_map[z][y] = ENNEMY;
	}
}

void	move_ennemy_up(t_game *game, int x, int y)
{
	if (game->map.full_map[x - 1][y] == FLOOR
		|| game->map.full_map[x - 1][y] == PLAYER)
	{
		change_sprites(game, &(game->floor), &(game->ennemy));
		--game->ennemy.pos_y;
		swap_tiles(game, x, y, x - 1);
	}
	else
		game->ennemy.is_going_up = 0;
}

void	move_ennemy_down(t_game *game, int x, int y)
{
	if (game->map.full_map[x + 1][y] == FLOOR
		|| game->map.full_map[x + 1][y] == PLAYER)
	{
		change_sprites(game, &(game->floor), &(game->ennemy));
		++game->ennemy.pos_y;
		swap_tiles(game, x, y, x + 1);
	}
	else
		game->ennemy.is_going_up = 1;
}

int	move_ennemy(t_game *game, int y, int x)
{
	if (game->ennemy.is_going_up == 1)
	{
		if (game->map.full_map[x - 1][y] == FLOOR
			|| game->map.full_map[x - 1][y] == PLAYER)
			move_ennemy_up(game, x, y);
		else
		{
			game->ennemy.is_going_up = 0;
			move_ennemy_down(game, x, y);
		}
	}
	else
	{
		if (game->map.full_map[x + 1][y] == FLOOR
			|| game->map.full_map[x + 1][y] == PLAYER)
			move_ennemy_down(game, x, y);
		else
		{
			game->ennemy.is_going_up = 1;
			move_ennemy_up(game, x, y);
		}
	}
	return (y);
}

void	count_ennemies(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full_map[i][j] == ENNEMY)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count > 1)
	{
		ft_printf("Error\nToo much ennemies on the map!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
}
