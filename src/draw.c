/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:32:12 by romain            #+#    #+#             */
/*   Updated: 2023/05/16 17:00:32 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_draw_line_x(t_fdf *fdf)
{

	f_init_line_x(fdf);
	f_proj(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
}

void f_draw_line_y(t_fdf *fdf)
{

	f_init_line_y(fdf);
	f_proj(fdf);
	f_app_scale(fdf);
	f_start_point(fdf);
	f_bresenham(fdf, get_rgba(255, 255, 255, 100));
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
		fdf->x = 0;
		fdf->y++;
	}
}