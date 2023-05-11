/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/11 11:58:01 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "42-FdF", false);
	if (!fdf->mlx)
		f_cleanup(fdf, "error");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	draw_point(fdf);
	f_draw_line(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}

void draw_point(t_fdf *fdf)
{
	int x;
	int y;
	int x1;
	int y1;

	x = 0;
	y = 0;
	x1 = 50;
	y1 = 50;
	while (y < fdf->width)
	{
		while (x < fdf->height)
		{
			if (x1 < HEIGHT -1 && y1 < WIDTH - 1)
				mlx_put_pixel(fdf->img, y1, x1, 0xF0F0F0);
			x1 += 50;
			x++;
		}
		x1 = 50;
		x = 0;
		y1 += 50;
		y++;
	}
}

void f_draw_line(t_fdf *fdf)
{
	int x;
	// int y;
	int color;

	x = 0;
	// y = 0;
	color = get_rgba(255, 255, 255, 100);
	fdf->scale = 50;
	fdf->bres->x1 = fdf->scale;
	while (x < fdf->width - 1)
	{
		f_draw_line_x(fdf);
		// f_draw_line_y(fdf);
		// fdf->bres->x1 += fdf->scale;
		x++;
	}
}



void f_draw_line_x(t_fdf *fdf)
{
	fdf->bres->x2 = fdf->scale + fdf->bres->x1;
	fdf->bres->y1 = fdf->scale;
	fdf->bres->y2 = fdf->scale;
	f_bresenham(fdf, get_rgba(255, 0, 0, 100));
}

void f_draw_line_y(t_fdf *fdf)
{
	fdf->bres->x1 = fdf->scale;
	fdf->bres->x2 = fdf->scale;
	fdf->bres->y1 = fdf->scale;
	fdf->bres->y2 = fdf->bres->y1 + fdf->scale;
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}









































void f_map_scale(t_fdf *fdf) //TODO revoir
{
	int i;
	i = 0;

	while (i < HEIGHT)
	{
		i += fdf->height;
		fdf->scale++;
	}
	if (fdf->scale < 1)
		fdf->scale = 10;
	else
		fdf->scale /= 2;
}