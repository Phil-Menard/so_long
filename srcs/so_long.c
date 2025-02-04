/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/04 14:12:39 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	get_map(&game.map);
	init_game(&game);
	init_sprites(&game);
	render_map(&game);
	mlx_key_hook(game.window, &handle_input, &game);
	mlx_hook(game.window, DestroyNotify, StructureNotifyMask, &end_game, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &destroy_all, &game);
	mlx_loop(game.mlx);
}
