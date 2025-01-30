/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:27 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/30 17:59:22 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
} */

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	//t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "./so_long");
	if (mlx_win == NULL)
		return (free(mlx_win), 1);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	/* img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); //ARGB(0,255,0,0)
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); */
}
