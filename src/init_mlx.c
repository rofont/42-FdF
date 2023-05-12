/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/12 16:36:32 by romain           ###   ########.fr       */
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
	// draw_point(fdf);
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
	while (fdf->y < fdf->height)
	{
		while (fdf->x < fdf->width)
		{
			if (fdf->x != fdf->width - 1)
			{
				// f_print_point(fdf);
				f_draw_line_x(fdf);
			}
			if (fdf->y != fdf->height -1)
			{
				// f_print_point(fdf);
				f_draw_line_y(fdf);
			}
			fdf->x++;
		}
		fdf->y++;
		fdf->x = 0;

	}
}

void f_draw_line_x(t_fdf *fdf)
{

	f_init_line_x(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 0, 0, 100));
}

void f_draw_line_y(t_fdf *fdf)
{

	f_init_line_y(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void f_init_line_x(t_fdf *fdf)
{
	fdf->bres->x1 = fdf->x;
	fdf->bres->x2 = fdf->x + 1;
	fdf->bres->y1 = fdf->y;
	fdf->bres->y2 = fdf->y;
}

void f_init_line_y(t_fdf *fdf)
{
	fdf->bres->x1 = fdf->x;
	fdf->bres->x2 = fdf->x;
	fdf->bres->y1 = fdf->y;
	fdf->bres->y2 = fdf->y + 1;
}

void f_app_scale(t_fdf *fdf)
{

	fdf->scale = 30;
	fdf->bres->x1 *= fdf->scale;
	fdf->bres->x2 *= fdf->scale;
	fdf->bres->y1 *= fdf->scale;
	fdf->bres->y2 *= fdf->scale;
}

void f_start_point(t_fdf *fdf)
{
	fdf->bres->x1 += 50;
	fdf->bres->y1 += 50;
	fdf->bres->x2 += 50;
	fdf->bres->y2 += 50;

}

