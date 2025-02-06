/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:52:06 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 14:02:05 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_stradd(char *s1, char *s2)
{
	char	*res;

	if (s1 == NULL)
	{
		res = ft_strdup(s2);
		return (res);
	}
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
		return (res);
	}
}

void	floodfill(int r, int c, t_map *map)
{
	if ((r < 0 || r >= map->rows || c < 0 || c >= map->columns)
		|| map->full_map[r][c] == 'v' || map->full_map[r][c] == WALL)
		return ;
	map->full_map[r][c] = 'v';
	floodfill(r, c + 1, map);
	floodfill(r, c - 1, map);
	floodfill(r + 1, c, map);
	floodfill(r - 1, c, map);
}

void	coins_counter(t_game *game)
{
	int	i;
	int	j;

	--game->total_coins;
	if (game->total_coins == 0)
	{
		i = 0;
		while (i < game->map.rows)
		{
			j = 0;
			while (j < game->map.columns)
			{
				if (game->map.full_map[i][j] == EXIT)
				{
					if (!game->exit_open.img)
						game->exit_open = new_sprite(game, EXIT_OPEN_PATH);
					mlx_put_image_to_window(game->mlx, game->window,
						game->exit_open.img, IMG_HEIGHT * j, IMG_WIDTH * i);
				}
				j++;
			}
			i++;
		}
	}
}

void	update_move_counter(t_game *game)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(game->move_count);
	str = ft_strjoin("movement count : ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->window, (game->map.columns * (IMG_WIDTH / 2)
			- 32), ((game->map.rows + 1) * IMG_HEIGHT) - 32, 0x000000, str);
	free(str);
	temp = ft_itoa(++game->move_count);
	str = ft_strjoin("movement count : ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->window, (game->map.columns * (IMG_WIDTH / 2)
			- 32), ((game->map.rows + 1) * IMG_HEIGHT) - 32, 0xFFFFFF, str);
	free(str);
}

t_map	cpy_map(t_map map)
{
	t_map	res;
	int		i;
	int		j;

	res.full_map = malloc((map.rows + 1) * sizeof (char *));
	i = 0;
	while (i < map.rows)
	{
		res.full_map[i] = ft_strdup(map.full_map[i]);
		j = 0;
		while (j < map.columns)
		{
			if (map.full_map[i][j] == PLAYER)
			{
				res.x = i;
				res.y = j;
			}
			j++;
		}
		i++;
	}
	res.full_map[i] = NULL;
	res.columns = map.columns;
	res.rows = map.rows;
	return (res);
}
