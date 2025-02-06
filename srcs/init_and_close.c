/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:52:42 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/06 15:40:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->coin.img)
		mlx_destroy_image(game->mlx, game->coin.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->exit_open.img)
		mlx_destroy_image(game->mlx, game->exit_open.img);
	if (game->ennemy.img)
		mlx_destroy_image(game->mlx, game->ennemy.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map.full_map)
		ft_free_2d((void **)game->map.full_map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	destroy_all(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
	{
		end_game(game);
	}
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit(EXIT_FAILURE);
	game->window = mlx_new_window(game->mlx, game->map.columns * IMG_WIDTH,
			(game->map.rows + 1) * IMG_HEIGHT, "so_long");
	if (game->window == NULL)
	{
		free(game->window);
		exit(EXIT_FAILURE);
	}
}

t_sprite	new_sprite(t_game *game, char *path)
{
	t_sprite	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path, &sprite.pos_x,
			&sprite.pos_y);
	if (!sprite.img)
	{
		ft_printf("Sprite not found.\n");
		end_game(game);
	}
	return (sprite);
}

void	init_sprites(t_game *game)
{
	game->wall.img = NULL;
	game->floor.img = NULL;
	game->coin.img = NULL;
	game->player.img = NULL;
	game->exit.img = NULL;
	game->exit_open.img = NULL;
	game->ennemy.img = NULL;
	game->wall = new_sprite(game, WALL_PATH);
	game->floor = new_sprite(game, FLOOR_PATH);
	game->coin = new_sprite(game, COIN_PATH);
	game->player = new_sprite(game, PLAYER_PATH);
	game->exit = new_sprite(game, EXIT_PATH);
	game->ennemy = new_sprite(game, ENNEMY_PATH);
	game->ennemy.is_going_up = -1;
}
