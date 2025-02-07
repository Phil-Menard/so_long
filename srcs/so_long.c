/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:37:04 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_game *game)
{
	ft_printf("Game over !\n");
	mlx_clear_window(game->mlx, game->window);
	mlx_string_put(game->mlx, game->window, (game->map.columns
			* (IMG_WIDTH / 2) - 32), ((game->map.rows)
			* ((IMG_HEIGHT / 2) + 12)) - 32, 0xFFFFFF, "GAME OVER LOOSER!");
	game->player.game_over = 1;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
	{
		ft_printf("Map is missing. It should be this way : 'map.ber'.\n");
		return (1);
	}
	else if (argc == 2)
	{
		get_map(&game, argv[1]);
		init_game(&game);
		init_sprites(&game);
		render_map(&game);
		mlx_key_hook(game.window, &handle_input, &game);
		mlx_hook(game.window, DestroyNotify, StructureNotifyMask,
			&end_game, &game);
		mlx_hook(game.window, KeyPress, KeyPressMask, &destroy_all, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_printf("Too much arguments. Only the map is needed.\n");
		return (1);
	}
}
