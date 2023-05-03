/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:53:54 by romain            #+#    #+#             */
/*   Updated: 2023/05/03 15:34:50 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_bresenham(int x, int y, int x1, int y1, mlx_image_t *img)
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
			mlx_put_pixel(img, x, y, 0xF0F0F0);
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
			mlx_put_pixel(img, x, y, 0xF0F0F0);
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