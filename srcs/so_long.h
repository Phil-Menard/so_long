/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/04 13:56:24 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <fcntl.h>

# define IMG_HEIGHT			64
# define IMG_WIDTH			64

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_UP 			65362
# define KEY_LEFT 			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN 			65364
# define KEY_ESC 			65307

# define WALL_PATH			"./assets/sprites/wall.xpm"
# define FLOOR_PATH			"./assets/sprites/floor.xpm"
# define COIN_PATH			"./assets/sprites/coin.xpm"
# define PLAYER_PATH		"./assets/sprites/player.xpm"
# define EXIT_PATH			"./assets/sprites/exit.xpm"

# define WALL				'1'
# define FLOOR 				'0'
# define COIN 				'C'
# define PLAYER				'P'
# define EXIT 		 		'E'

typedef struct s_map
{
	char	**full_map;
	int		rows;
	int		columns;
}	t_map;

typedef struct s_sprite
{
	void	*img;
	char	*path;
	int		pos_x;
	int		pos_y;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			total_coins;
	int			move_count;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	coin;
	t_sprite	exit;
	t_map		map;
}	t_game;

void	get_map(t_map *map);
int		render_map(t_game *game);
int		handle_input(int keysym, t_game *game);
int		end_game(t_game *game);
int		destroy_all(int keysym, t_game *game);
void	init_game(t_game *game);
void	init_sprites(t_game *game);
void	update_player_pos(t_game *game, int x, int y);
void	move_player(t_game *game, int x, int y);
char	*ft_stradd(char *s1, char *s2);

#endif