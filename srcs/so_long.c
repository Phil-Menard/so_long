/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 23:53:39 by pmenard          ###   ########.fr       */
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
	mlx_hook(game.window, KeyRelease, KeyReleaseMask, &handle_input, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &destroy_all, &game);
	mlx_loop(game.mlx);
}

//mlx_loop_hook(game.mlx, &render_map, &game);