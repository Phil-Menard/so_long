/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 23:18:44 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_all(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_image(game->mlx, game->player.img);
		mlx_destroy_image(game->mlx, game->wall.img);
		mlx_destroy_image(game->mlx, game->floor.img);
		mlx_destroy_image(game->mlx, game->coin.img);
		mlx_destroy_image(game->mlx, game->exit.img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_free_2d((void **)game->map.full_map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit(EXIT_FAILURE);
	game->window = mlx_new_window(game->mlx, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "so_long");
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
		ft_printf("Sprite not found.\n");
	return (sprite);
}

void	init_sprites(t_game *game)
{
	game->wall = new_sprite(game, WALL_PATH);
	game->floor = new_sprite(game, FLOOR_PATH);
	game->coin = new_sprite(game, COIN_PATH);
	game->player = new_sprite(game, PLAYER_PATH);
	game->exit = new_sprite(game, EXIT_PATH);
}

int	main(void)
{
	t_game	game;

	get_map(&game.map);
	init_game(&game);
	init_sprites(&game);
	render_map(&game);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, &handle_input, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &destroy_all, &game);
	mlx_loop(game.mlx);
}

//mlx_loop_hook(game.mlx, &render_map, &game);