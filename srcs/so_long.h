/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 18:03:51 by pmenard          ###   ########.fr       */
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

# define WALL				'1'
# define FLOOR 				'0'
# define COINS 				'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_UP 			65362
# define KEY_LEFT 			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN 			65364

typedef struct s_map
{
	char	**full_map;
	int		rows;
	int		columns;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*path;
	int			width;
	int			height;
	t_player	player;
	t_map		map;
}	t_game;

char	*ft_stradd(char *s1, char *s2);

#endif