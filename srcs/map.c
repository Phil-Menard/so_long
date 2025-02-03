/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:44:34 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 20:48:14 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_map *map)
{
	int		map_fd;
	char	*file_content;
	char	*temp_map;

	temp_map = NULL;
	map_fd = open("./assets/maps/basic.ber", O_RDONLY);
	if (map_fd == -1)
		return (perror("open"), exit(EXIT_FAILURE));
	map->rows = 0;
	file_content = get_next_line(map_fd);
	while (file_content != NULL)
	{
		temp_map = ft_stradd(temp_map, file_content);
		map->rows++;
		free(file_content);
		file_content = get_next_line(map_fd);
	}
	map->full_map = ft_split(temp_map, '\n');
	map->columns = ft_strlen(map->full_map[0]);
	free(temp_map);
	free(file_content);
	close(map_fd);
}

void	fill_map(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map.full_map[y][x];
	if (pos == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->wall.img,
			game->wall.pos_x * x, game->wall.pos_y * y);
	else if (pos == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
			game->floor.pos_x * x, game->floor.pos_y * y);
	else if (pos == COIN)
		mlx_put_image_to_window(game->mlx, game->window, game->coin.img,
			game->coin.pos_x * x, game->coin.pos_y * y);
	else if (pos == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window, game->player.img,
			game->player.pos_x * x, game->player.pos_y * y);
	else if (pos == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->exit.img,
			game->exit.pos_x * x, game->exit.pos_y * y);
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			fill_map(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
