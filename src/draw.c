/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:53:54 by romain            #+#    #+#             */
/*   Updated: 2023/05/04 14:14:35 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_bresenham(int x, int y, int x1, int y1, mlx_image_t *img, int color)
{
	int ex = abs(x1 - x);
	int ey = abs(y1 - y);
	int dx = 2*ex;
	int dy = 2*ey;
	int Dx = ex;
	int Dy = ey;
	int i = 0;
	int xi = 1;
	int yi = 1;

	if (x > x1)
		xi = -1;
	if (y > y1)
		yi = -1;
	if (Dx >= Dy)
	{
		while (i <= Dx)
		{
			if (x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, color);
			i++;
			x += xi;
			ex -= dy;
			if (ex < 0)
			{
				y += yi;
				ex+= dx;
			}
		}
	}
	if (Dx < Dy)
	{
		while (i <= Dy)
		{
			if (x < WIDTH && y < HEIGHT)
				mlx_put_pixel(img, x, y, color);
			i++;
			y += yi;
			ey -= dx;
			if (ey < 0)
			{
				x += xi;
				ey+= dy;
			}
		}
	}
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