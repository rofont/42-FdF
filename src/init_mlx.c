/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/15 13:30:07 by rofontai         ###   ########.fr       */
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
	f_proj(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 0, 0, 100));
}

void f_draw_line_y(t_fdf *fdf)
{

	f_init_line_y(fdf);
	f_proj(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void f_init_line_x(t_fdf *fdf)
{
	fdf->points->x1 = fdf->x;
	fdf->points->x2 = fdf->x + 1;
	fdf->points->y1 = fdf->y;
	fdf->points->y2 = fdf->y;
	fdf->points->z1 = fdf->map[fdf->y][fdf->x];
	fdf->points->z2 = fdf->map[fdf->y][fdf->x + 1];
}

void f_init_line_y(t_fdf *fdf)
{
	fdf->points->x1 = fdf->x;
	fdf->points->x2 = fdf->x;
	fdf->points->y1 = fdf->y;
	fdf->points->y2 = fdf->y + 1;
	fdf->points->z1 = fdf->map[fdf->y][fdf->x];
	fdf->points->z2 = fdf->map[fdf->y + 1][fdf->x];
}

void f_app_scale(t_fdf *fdf)
{

	fdf->scale = 50;
	fdf->points->p_x1 *= fdf->scale;
	fdf->points->p_x2 *= fdf->scale;
	fdf->points->p_y1 *= fdf->scale;
	fdf->points->p_y2 *= fdf->scale;
}

void f_start_point(t_fdf *fdf)
{
	fdf->points->p_x1 += 20;
	fdf->points->p_y1 += 20;
	fdf->points->p_x2 += 20;
	fdf->points->p_y2 += 20;

}

void f_proj(t_fdf *fdf)
{
	const double angle = 45 * M_PI / 180.0;

	fdf->points->p_x1 = (fdf->points->x1 - fdf->points->y1) * cos(angle);
	fdf->points->p_y1 = (fdf->points->x1 + fdf->points->y1) * cos(angle) - fdf->points->z1;
	fdf->points->p_x2 = (fdf->points->x2 - fdf->points->y2) * cos(angle);
	fdf->points->p_y2 = (fdf->points->x2 + fdf->points->y2) * cos(angle) - fdf->points->z2;
}