/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/31 14:44:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#  define RED_PIXEL 0xFF0000
#  define GREEN_PIXEL 0xFF00
#  define WHITE_PIXEL 0xFFFFFF

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; //bits_per_pixel
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_img	img;
}	t_data;

#endif