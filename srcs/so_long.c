/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 17:56:14 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	if (game->window == NULL)
		return (1);
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->img,
		game->player.pos_x, game->player.pos_y);
	return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == KEY_UP)
		game->player.pos_y -= 32;
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		game->player.pos_y += 32;
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		game->player.pos_x -= 32;
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		game->player.pos_x += 32;
	return (0);
}

int	destroy_all(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_image(game->mlx, game->img);
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
	game->path = "./assets/sprites/player.xpm";
	game->player.pos_x = 64;
	game->player.pos_y = 64;
}

void	init_map(t_game *game)
{
	int		map_fd;
	char	*file_content;
	char	*map;

	map = NULL;
	map_fd = open("./assets/maps/basic.ber", O_RDONLY);
	if (map_fd == -1)
		return (perror("open"), exit(EXIT_FAILURE));
	game->map.rows = 0;
	file_content = get_next_line(map_fd);
	while (file_content != NULL)
	{
		map = ft_stradd(map, file_content);
		game->map.rows++;
		free(file_content);
		file_content = get_next_line(map_fd);
	}
	game->map.full_map = ft_split(map, '\n');
	game->map.columns = ft_strlen(game->map.full_map[0]);
	ft_printf("rows : %d\n", game->map.rows);
	ft_printf("columns : %d\n", game->map.columns);
	free(map);
	free(file_content);
	close(map_fd);
}

int	main(void)
{
	t_game	game;

	init_map(&game);
	init_game(&game);
	game.img = mlx_xpm_file_to_image(game.mlx, game.path,
			&game.width, &game.height);
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, &handle_input, &game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &destroy_all, &game);
	mlx_loop(game.mlx);
}
