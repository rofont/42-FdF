/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:35 by romain            #+#    #+#             */
/*   Updated: 2023/05/16 16:46:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void f_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "42-FdF", false);
	if (!fdf->mlx)
		f_cleanup(fdf, "error");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	f_draw_line(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}