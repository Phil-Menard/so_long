/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:49:58 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/04 15:26:14 by pmenard          ###   ########.fr       */
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

void	check_map(t_game *game)
{
	if (game->map.columns == game->map.rows)
	{
		ft_printf("Error\nThis map is not rectangular!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
	if (surrounded_by_walls(game) == 1)
	{
		ft_printf("Error\nThe map is not surrounded by walls!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
}
