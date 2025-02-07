/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:49:58 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:43:07 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	surrounded_by_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		if (y == 0 || y == game->map.rows - 1)
		{
			x = 0;
			while (x < game->map.columns)
			{
				if (game->map.full_map[y][x] != WALL)
					return (1);
				x++;
			}
		}
		else
		{
			if (game->map.full_map[y][0] != WALL
				|| game->map.full_map[y][game->map.columns - 1] != WALL)
				return (1);
		}
		y++;
	}
	return (0);
}

void	check_nb_player(t_game *game)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (game->map.full_map[i])
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.full_map[i][j] == PLAYER)
				counter++;
		}
		i++;
	}
	if (counter != 1)
	{
		if (counter == 0)
			ft_printf("Error\nThere is no player!\n");
		else if (counter > 1)
			ft_printf("Error\nThere are too many players!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
}

void	check_unknown_tile(t_game *game)
{
	int		i;
	int		j;
	char	tile;

	i = 0;
	while (i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			tile = game->map.full_map[i][j];
			if (tile != WALL && tile != FLOOR && tile != COIN
				&& tile != PLAYER && tile != EXIT && tile != ENNEMY)
			{
				ft_printf("Error\nThe map file isn't correct!\n");
				ft_free_2d((void **)game->map.full_map);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	t_map	map_cpy;

	if (game->map.columns == game->map.rows)
	{
		ft_printf("Error\nThis map is not rectangular!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
	check_unknown_tile(game);
	if (surrounded_by_walls(game) == 1)
	{
		ft_printf("Error\nThe map is not surrounded by walls!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
	check_nb_player(game);
	check_exit(game);
	map_cpy = cpy_map(game->map);
	floodfill(map_cpy.x, map_cpy.y, &map_cpy, 0);
	check_way(&map_cpy, game);
	ft_free_2d((void **)map_cpy.full_map);
	map_cpy = cpy_map(game->map);
	floodfill(map_cpy.x, map_cpy.y, &map_cpy, 1);
	check_way_coin(&map_cpy, game);
	ft_free_2d((void **)map_cpy.full_map);
}
