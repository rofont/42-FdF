/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:53:54 by romain            #+#    #+#             */
/*   Updated: 2023/05/12 16:21:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_bresenham(t_fdf *fdf, int color)
{
	int i;

	i = 0;
	f_modif_bres(fdf->bres);
	if (fdf->bres->x1 > fdf->bres->x2)
		fdf->bres->xi = -1;
	if (fdf->bres->y1 > fdf->bres->y2)
		fdf->bres->yi = -1;
	if (fdf->bres->Dx >= fdf->bres->Dy)
		f_draw_x(fdf, i, color);
	if (fdf->bres->Dx < fdf->bres->Dy)
		f_draw_y(fdf, i, color);
}

t_point *calc_isometric(t_point *pts, int max_pts)
{
    float   x;
    float   y;
    float   z;
    const double angle = 30 * M_PI / 180.0;
    int num_pts;

    num_pts = 0;
    while (num_pts < max_pts)
    {
        x = pts[num_pts].x;
        y = pts[num_pts].y;
        z = pts[num_pts].z;
        // printf("x: %f y: %f z: %f\n", x, y, z);
        pts[num_pts].x = (x - y) * cos(angle);
        pts[num_pts].y = (x + y) * sin(angle) - z;
        // printf("x_iso %f\ty_iso %f\n\n", pts[num_pts].x, pts[num_pts].y);
        num_pts++;
    }
    return (pts);
}