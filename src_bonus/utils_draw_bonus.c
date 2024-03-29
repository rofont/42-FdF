/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:34:39 by romain            #+#    #+#             */
/*   Updated: 2023/05/19 12:45:15 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_init_line_x(t_fdf *fdf)
{
	fdf->points->x1 = fdf->x;
	fdf->points->x2 = fdf->x + 1;
	fdf->points->y1 = fdf->y;
	fdf->points->y2 = fdf->y;
	fdf->points->z1 = fdf->map[fdf->y][fdf->x];
	fdf->points->z2 = fdf->map[fdf->y][fdf->x + 1];
}

void	f_init_line_y(t_fdf *fdf)
{
	fdf->points->x1 = fdf->x;
	fdf->points->x2 = fdf->x;
	fdf->points->y1 = fdf->y;
	fdf->points->y2 = fdf->y + 1;
	fdf->points->z1 = fdf->map[fdf->y][fdf->x];
	fdf->points->z2 = fdf->map[fdf->y + 1][fdf->x];
}

void	f_app_scale(t_fdf *fdf)
{
	fdf->points->x1 *= fdf->scale + fdf->cam->zoom;
	fdf->points->x2 *= fdf->scale + fdf->cam->zoom;
	fdf->points->y1 *= fdf->scale + fdf->cam->zoom;
	fdf->points->y2 *= fdf->scale + fdf->cam->zoom;
}

void	f_projection(t_fdf *fdf)
{
	double	angle;

	angle = 30 * M_PI / 180.0;
	if (fdf->cam->iso == 0)
	{
		fdf->points->p_x1 = (fdf->points->x1 - fdf->points->y1)
			* cos(angle + fdf->cam->angle);
		fdf->points->p_y1 = (fdf->points->x1 + fdf->points->y1)
			* sin(angle + fdf->cam->angle)
			- (fdf->points->z1 * fdf->cam->offset_z);
		fdf->points->p_x2 = (fdf->points->x2 - fdf->points->y2)
			* cos(angle + fdf->cam->angle);
		fdf->points->p_y2 = (fdf->points->x2 + fdf->points->y2)
			* sin(angle + fdf->cam->angle)
			- (fdf->points->z2 * fdf->cam->offset_z);
	}
	if (fdf->cam->iso == 1)
	{
		fdf->points->p_x1 = fdf->points->x1;
		fdf->points->p_y1 = fdf->points->y1;
		fdf->points->p_x2 = fdf->points->x2;
		fdf->points->p_y2 = fdf->points->y2;
	}
}

void	f_start_point(t_fdf *fdf)
{
	fdf->points->p_x1 += WIDTH / 2 - (fdf->width * fdf->scale) / 2 + WIDTH / 6;
	fdf->points->p_y1 += HEIGHT / 4;
	fdf->points->p_x2 += WIDTH / 2 - (fdf->width * fdf->scale) / 2 + WIDTH / 6;
	fdf->points->p_y2 += HEIGHT / 4;
}
