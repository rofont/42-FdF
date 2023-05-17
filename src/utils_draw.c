/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:35:07 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 09:15:46 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

	fdf->scale = 10;
	fdf->points->x1 *= fdf->scale;
	fdf->points->x2 *= fdf->scale;
	fdf->points->y1 *= fdf->scale;
	fdf->points->y2 *= fdf->scale;
}

void f_start_point(t_fdf *fdf)
{
	fdf->points->p_x1 += WIDTH/4;
	fdf->points->p_y1 += HEIGHT/4;
	fdf->points->p_x2 += WIDTH/4;
	fdf->points->p_y2 += HEIGHT/4;

}

void f_proj(t_fdf *fdf)
{
	double angle = 30 * M_PI / 180.0;

	fdf->points->p_x1 = (fdf->points->x1 - fdf->points->y1) * cos(angle);
	fdf->points->p_y1 = (fdf->points->x1 + fdf->points->y1) * sin(angle) - fdf->points->z1;
	fdf->points->p_x2 = (fdf->points->x2 - fdf->points->y2) * cos(angle);
	fdf->points->p_y2 = (fdf->points->x2 + fdf->points->y2) * sin(angle) - fdf->points->z2;
}