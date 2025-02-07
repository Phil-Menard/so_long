/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:11:49 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:56:43 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_way(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->full_map[i])
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->full_map[i][j] == COIN || map->full_map[i][j] == EXIT)
			{
				ft_printf("Error\nThe level is impossible to finish!\n");
				ft_free_2d((void **)map->full_map);
				ft_free_2d((void **)game->map.full_map);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_way_coin(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->full_map[i])
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->full_map[i][j] == COIN)
			{
				ft_printf("Error\nThe level is impossible to finish!\n");
				ft_free_2d((void **)map->full_map);
				ft_free_2d((void **)game->map.full_map);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	count_ennemies(game);
}

void	check_exit(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map.full_map[i])
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.full_map[i][j] == EXIT)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_printf("Error\nThere should be one exit!\n");
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_FAILURE);
	}
}
