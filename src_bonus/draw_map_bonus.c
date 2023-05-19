/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:31:38 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 22:07:27 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_draw_line(t_fdf *fdf)
{
	// f_magic_board(fdf);
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

void	f_draw_line_x(t_fdf *fdf)
{
	f_init_line_x(fdf);
	f_app_scale(fdf);
	f_projection(fdf);
	f_translate(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void	f_draw_line_y(t_fdf *fdf)
{
	f_init_line_y(fdf);
	f_app_scale(fdf);
	f_projection(fdf);
	f_translate(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void	f_scale(t_fdf *fdf)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < WIDTH && y < HEIGHT)
	{
		i += fdf->width;
		y += fdf->height;
		fdf->scale++;
	}
	fdf->scale /= 2;
}

void	f_translate(t_fdf *fdf)
{
	fdf->points->p_x1 += fdf->cam->offset_x;
	fdf->points->p_y1 += fdf->cam->offset_y;
	fdf->points->p_x2 += fdf->cam->offset_x;
	fdf->points->p_y2 += fdf->cam->offset_y;
}