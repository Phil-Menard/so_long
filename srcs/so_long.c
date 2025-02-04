/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/04 15:26:23 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
