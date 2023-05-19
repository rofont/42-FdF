/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:50:26 by romain            #+#    #+#             */
/*   Updated: 2023/05/19 15:09:00 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_modif_bres(t_fdf *fdf)
{
		fdf->bres->ex = fabs(fdf->points->p_x2 - fdf->points->p_x1);
		fdf->bres->ey = fabs(fdf->points->p_y2 - fdf->points->p_y1);
		fdf->bres->dx = 2 * fdf->bres->ex;
		fdf->bres->dy = 2 * fdf->bres->ey;
		fdf->bres->Dx = fdf->bres->ex;
		fdf->bres->Dy = fdf->bres->ey;
		fdf->bres->xi = 1;
		fdf->bres->yi = 1;
}

void	f_draw_x(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= fdf->bres->Dx)
	{
		if (fdf->points->p_x1 > 0 && fdf->points->p_y1 > 0
			&& fdf->points->p_x1 < WIDTH && fdf->points->p_y1 < HEIGHT)
			mlx_put_pixel(fdf->img, fdf->points->p_x1, fdf->points->p_y1,
				fdf->cam->colors);
		i++;
		fdf->points->p_x1 += fdf->bres->xi;
		fdf->bres->ex -= fdf->bres->dy;
		if (fdf->bres->ex < 0)
		{
			fdf->points->p_y1 += fdf->bres->yi;
			fdf->bres->ex += fdf->bres->dx;
		}
	}
}

void	f_draw_y(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= fdf->bres->Dy)
	{
		if (fdf->points->p_x1 > 0 && fdf->points->p_y1 > 0
			&& fdf->points->p_x1 < WIDTH && fdf->points->p_y1 < HEIGHT)
			mlx_put_pixel(fdf->img, fdf->points->p_x1, fdf->points->p_y1,
				fdf->cam->colors);
		i++;
		fdf->points->p_y1 += fdf->bres->yi;
		fdf->bres->ey -= fdf->bres->dx;
		if (fdf->bres->ey < 0)
		{
			fdf->points->p_x1 += fdf->bres->xi;
			fdf->bres->ey += fdf->bres->dy;
		}
	}
}

void	f_bresenham(t_fdf *fdf)
{
	f_modif_bres(fdf);
	if (fdf->points->p_x1 > fdf->points->p_x2)
		fdf->bres->xi = -1;
	if (fdf->points->p_y1 > fdf->points->p_y2)
		fdf->bres->yi = -1;
	if (fdf->bres->Dx >= fdf->bres->Dy)
		f_draw_x(fdf);
	if (fdf->bres->Dx < fdf->bres->Dy)
		f_draw_y(fdf);
}
