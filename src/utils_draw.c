/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:16:27 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/11 10:24:42 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_modif_bres(t_bres *new)
{
		new->ex = abs(new->x2 - new->x1);
		new->ey = abs(new->y2 - new->y1);
		new->dx = 2*new->ex;
		new->dy = 2*new->ey;
		new->Dx = new->ex;
		new->Dy = new->ey;
		new->xi = 1;
		new->yi = 1;
}

void f_draw_x(t_fdf *fdf, int i, int color)
{
	while (i <= fdf->bres->Dx)
	{
		if (fdf->bres->x1 < WIDTH && fdf->bres->y1 < HEIGHT)
			mlx_put_pixel(fdf->img, fdf->bres->x1, fdf->bres->y1, color);
		i++;
		fdf->bres->x1 += fdf->bres->xi;
		fdf->bres->ex -= fdf->bres->dy;
		if (fdf->bres->ex < 0)
		{
			fdf->bres->y1 += fdf->bres->yi;
			fdf->bres->ex+= fdf->bres->dx;
		}
	}
}

void f_draw_y(t_fdf *fdf, int i, int color)
{
	while (i <= fdf->bres->Dy)
	{
		if (fdf->bres->x1 < WIDTH && fdf->bres->y1 < HEIGHT)
			mlx_put_pixel(fdf->img, fdf->bres->x1, fdf->bres->y1, color);
		i++;
		fdf->bres->y1 += fdf->bres->yi;
		fdf->bres->ey -= fdf->bres->dx;
		if (fdf->bres->ey < 0)
		{
			fdf->bres->x1 += fdf->bres->xi;
			fdf->bres->ey+= fdf->bres->dy;
		}
	}
}