/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/03 15:34:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


void f_init_mlx(t_fdf *fdf)
{
	mlx_t *mlx;
	mlx_image_t *img;

	mlx = mlx_init(WIDTH, HEIGHT, "42-FdF", true);
	if (!mlx)
		f_cleanup(fdf, "error");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	draw_point(img, fdf);
	f_draw_line(fdf, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

void draw_point(mlx_image_t *img, t_fdf *fdf)
{
	int x;
	int y;
	int x1;
	int y1;

	x = 0;
	y = 0;
	x1 = 10;
	y1 = 10;
	while (y < fdf->width)
	{
		while (x < fdf->height)
		{
			mlx_put_pixel(img, y1, x1, 0xF0F0F0);
			x1 += fdf->scale;
			x++;
		}
		x1 = 10;
		x = 0;
		y1 += fdf->scale;
		y++;
	}
}

void f_draw_line(t_fdf *fdf, mlx_image_t *img)
{
	int x;
	int y;
	int x1;
	int y1;

	x = 0;
	y =	0;
	x1 = 10;
	y1 = 10;
	while (y < fdf->height)
	{
		while (x < fdf->width)
		{
			if (x != fdf->width -1)
				f_bresenham(x1, y1, (x1 + fdf->scale), y1, img);
			if (y != fdf->height -1)
				f_bresenham(x1, y1, x1, (y1 + fdf->scale), img);
			x1 += fdf->scale;
			x++;
		}
		x = 0;
		x1 = 10;
		y1 += fdf->scale;
		y ++;
	}
}