/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:44:34 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 19:09:02 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game *game, char *argv)
{
	int		map_fd;
	char	*file_content;
	char	*temp_map;

	temp_map = NULL;
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		return (perror(argv), exit(EXIT_FAILURE));
	game->map.rows = 0;
	file_content = get_next_line(map_fd);
	while (file_content != NULL)
	{
		temp_map = ft_stradd(temp_map, file_content);
		game->map.rows++;
		free(file_content);
		file_content = get_next_line(map_fd);
	}
	game->map.full_map = ft_split(temp_map, '\n');
	game->map.columns = ft_strlen(game->map.full_map[0]);
	free(temp_map);
	free(file_content);
	close(map_fd);
	check_map(game);
}

void	set_player_pos(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player.img,
		IMG_HEIGHT * x, IMG_WIDTH * y);
	game->player.pos_x = x;
	game->player.pos_y = y;
}

void	set_ennemy_pos(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->ennemy.img,
		IMG_HEIGHT * x, IMG_WIDTH * y);
	game->ennemy.pos_x = x;
	game->ennemy.pos_y = y;
	game->ennemy.is_going_up = 1;
}

void	fill_map(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map.full_map[y][x];
	if (pos == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->wall.img,
			IMG_HEIGHT * x, IMG_WIDTH * y);
	else if (pos == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
			IMG_HEIGHT * x, IMG_WIDTH * y);
	else if (pos == COIN)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->coin.img,
			IMG_HEIGHT * x, IMG_WIDTH * y);
		++game->total_coins;
	}
	else if (pos == PLAYER)
		set_player_pos(game, x, y);
	else if (pos == ENNEMY)
		set_ennemy_pos(game, x, y);
	else if (pos == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->exit.img,
			IMG_HEIGHT * x, IMG_WIDTH * y);
}

int	render_map(t_game *game)
{
	int		y;
	int		x;
	char	*temp;
	char	*str;

	game->total_coins = 0;
	game->move_count = 0;
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
	temp = ft_itoa(game->move_count);
	str = ft_strjoin("movement count : ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->window, (game->map.columns * (IMG_WIDTH / 2)
			- 32), ((game->map.rows + 1) * IMG_HEIGHT) - 32, 0xFFFFFF, str);
	free(str);
	return (0);
}
