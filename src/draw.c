/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:32:12 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 10:55:40 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_start(t_fdf *fdf)
{
	int c;
	int pw_c;

	pw_c = 0;
	c = 0;

	pw_c = pow(fdf->height, 2) + pow(fdf->width, 2);
	c = sqrt(pw_c);


	fdf->start_x = WIDTH/4 + c + WIDTH/8;
	fdf->start_y = HEIGHT/4 + c;
}



void f_scale(t_fdf *fdf)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i < WIDTH  && y < HEIGHT)
	{
		i += fdf->width;
		y += fdf->height;
		fdf->scale++;
	}
	fdf->scale /= 2;
}

void f_draw_line_x(t_fdf *fdf)
{

	f_init_line_x(fdf);
	f_app_scale(fdf);
	f_proj(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void f_draw_line_y(t_fdf *fdf)
{

	f_init_line_y(fdf);
	f_app_scale(fdf);
	f_proj(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void f_draw_line(t_fdf *fdf)
{
	f_scale(fdf);
	f_start(fdf);
	while (fdf->y < fdf->height)
	{
		while (fdf->x < fdf->width)
		{
			if (fdf->x != fdf->width - 1)
				f_draw_line_x(fdf);
			if (fdf->y != fdf->height -1)
				f_draw_line_y(fdf);
			fdf->x++;
		}
		fdf->x = 0;
		fdf->y++;
	}
}