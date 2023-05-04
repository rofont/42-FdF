/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/04 14:33:24 by rofontai         ###   ########.fr       */
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
	// draw_point(img, fdf);
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
	void f_map_scale(t_fdf *fdf);
	x1 = 10;
	y1 = 10;
	while (y < fdf->width)
	{
		while (x < fdf->height)
		{
			mlx_put_pixel(img, y1, x1, 0xF0F0F0);
			x1 += 10;
			x++;
		}
		x1 = 10;
		x = 0;
		y1 += 10;
		y++;
	}
}

void f_draw_line(t_fdf *fdf, mlx_image_t *img)
{
	int x;
	int y;
	int x1;
	int y1;
	int color;

	color = get_rgba(255, 255, 0, 100);
	x = 0;
	y =	0;
	f_map_scale(fdf);
	x1 = (WIDTH/2) - ((fdf->width*fdf->scale)/2);
	y1 = (HEIGHT/2) - ((fdf->height*fdf->scale)/2);
	while (y < fdf->height)
	{
		while (x < fdf->width)
		{
			if (x != fdf->width -1)
			{
				if (fdf->map[y][x] > 0)
					color = 0xF0F0F0;
				f_bresenham(x1, y1, (x1 + fdf->scale), y1, img, color);
			}
			if (y != fdf->height -1)
			{
				if (fdf->map[y][x] > 0)
					color = 0xF0F0F0;
				f_bresenham(x1, y1, x1, (y1 + fdf->scale), img, color);
			}
			color = get_rgba(255, 255, 0, 100);
			x1 += fdf->scale;
			x++;
		}
		x = 0;
		x1 = (WIDTH/2) - ((fdf->width*fdf->scale)/2);
		y1 += fdf->scale;
		y ++;
	}
}

void f_map_scale(t_fdf *fdf)
{
	int i;
	i = 0;

	while (i < HEIGHT)
	{
		i += fdf->height;
		fdf->scale++;
	}
	fdf->scale /= 2;
}