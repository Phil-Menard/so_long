/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:41:48 by pmenard          ###   ########.fr       */
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
# define KEY_UP				65362
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define KEY_ESC			65307

# define WALL_PATH			"./assets/sprites/wall.xpm"
# define FLOOR_PATH			"./assets/sprites/floor.xpm"
# define COIN_PATH			"./assets/sprites/coin.xpm"
# define PLAYER_PATH		"./assets/sprites/player.xpm"
# define EXIT_PATH			"./assets/sprites/exit.xpm"
# define EXIT_OPEN_PATH		"./assets/sprites/exit_open.xpm"
# define ENNEMY_PATH		"./assets/sprites/ennemy.xpm"

# define WALL				'1'
# define FLOOR				'0'
# define COIN				'C'
# define PLAYER				'P'
# define EXIT				'E'
# define ENNEMY				'X'

typedef struct s_map
{
	char	**full_map;
	int		rows;
	int		columns;
	int		x;
	int		y;
}	t_map;

typedef struct s_sprite
{
	void	*img;
	char	*path;
	int		pos_x;
	int		pos_y;
	int		is_going_up;
	int		is_going_down;
	int		is_on_coin;
	int		game_over;
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
	t_sprite	exit_open;
	t_sprite	ennemy;
	t_map		map;
}	t_game;

void		check_map(t_game *game);
void		check_exit(t_game *game);
int			render_map(t_game *game);
void		get_map(t_game *game, char *argv);
void		check_exit(t_game *game);
t_map		cpy_map(t_map map);
int			handle_input(int keysym, t_game *game);
int			end_game(t_game *game);
void		game_over(t_game *game);
void		check_way(t_map *map, t_game *game);
void		check_way_coin(t_map *map, t_game *game);
int			destroy_all(int keysym, t_game *game);
void		init_game(t_game *game);
t_sprite	new_sprite(t_game *game, char *path);
void		init_sprites(t_game *game);
void		change_sprites(t_game *game, t_sprite *sprite, t_sprite *character);
void		update_player_pos(t_game *game, int x, int y);
void		count_ennemies(t_game *game);
int			move_ennemy(t_game *game, int x, int y);
void		move_player(t_game *game, int x, int y);
char		*ft_stradd(char *s1, char *s2);
void		floodfill(int r, int c, t_map *map, int x);
void		coins_counter(t_game *game);
void		update_move_counter(t_game *game);

#endif