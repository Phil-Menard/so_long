/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:26 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:52:53 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_tiles(t_game *game, int x, int y, int z)
{
	if (game->map.full_map[z][y] == PLAYER)
		game_over(game);
	else if (game->map.full_map[x][y] == PLAYER && game->ennemy.is_going_up == 1
		&& game->player.is_going_down == 1)
		game_over(game);
	else if (game->map.full_map[x][y] == PLAYER && game->ennemy.is_going_up == 0
		&& game->player.is_going_up == 1)
		game_over(game);
	else
	{
		if (game->ennemy.is_on_coin == 1)
		{
			game->map.full_map[x][y] = COIN;
			game->map.full_map[z][y] = ENNEMY;
		}
		if (game->ennemy.is_on_coin == 0 && game->map.full_map[z][y] != COIN)
		{
			game->map.full_map[x][y] = FLOOR;
			game->map.full_map[z][y] = ENNEMY;
		}
		change_sprites(game, &(game->ennemy), &(game->ennemy));
	}
}

void	move_ennemy_up(t_game *game, int x, int y)
{
	if (game->map.full_map[x - 1][y] != EXIT
			&& game->map.full_map[x - 1][y] != WALL)
	{
		if (game->ennemy.is_on_coin == 1)
		{
			if (game->map.full_map[x][y] != PLAYER)
				change_sprites(game, &(game->coin), &(game->ennemy));
			--game->ennemy.pos_y;
			swap_tiles(game, x, y, x - 1);
			game->ennemy.is_on_coin = 0;
		}
		else
		{
			if (game->map.full_map[x][y] != PLAYER)
				change_sprites(game, &(game->floor), &(game->ennemy));
			--game->ennemy.pos_y;
			swap_tiles(game, x, y, x - 1);
		}
		if (game->map.full_map[x - 1][y] == COIN)
			game->ennemy.is_on_coin = 1;
	}
	else
		game->ennemy.is_going_up = 0;
}

void	move_ennemy_down(t_game *game, int x, int y)
{
	if (game->map.full_map[x + 1][y] != EXIT
			&& game->map.full_map[x + 1][y] != WALL)
	{
		if (game->ennemy.is_on_coin == 1)
		{
			if (game->map.full_map[x][y] != PLAYER)
				change_sprites(game, &(game->coin), &(game->ennemy));
			++game->ennemy.pos_y;
			swap_tiles(game, x, y, x + 1);
			game->ennemy.is_on_coin = 0;
		}
		else
		{
			if (game->map.full_map[x][y] != PLAYER)
				change_sprites(game, &(game->floor), &(game->ennemy));
			++game->ennemy.pos_y;
			swap_tiles(game, x, y, x + 1);
		}
		if (game->map.full_map[x + 1][y] == COIN)
			game->ennemy.is_on_coin = 1;
	}
	else
		game->ennemy.is_going_up = 1;
}

int	move_ennemy(t_game *game, int y, int x)
{
	if (game->ennemy.is_going_up == 1)
	{
		if (game->map.full_map[x - 1][y] != EXIT
			&& game->map.full_map[x - 1][y] != WALL)
			move_ennemy_up(game, x, y);
		else
		{
			game->ennemy.is_going_up = 0;
			move_ennemy_down(game, x, y);
		}
	}
	else
	{
		if (game->map.full_map[x + 1][y] != EXIT
			&& game->map.full_map[x + 1][y] != WALL)
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
