/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_zero_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:37:09 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/19 11:16:40 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_fdf_zero(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	f_bres_zero(fdf);
	f_points_zero(fdf);
}

void	f_bres_zero(t_fdf *fdf)
{
	fdf->bres->ex = 0;
	fdf->bres->dx = 0;
	fdf->bres->Dx = 0;
	fdf->bres->xi = 0;
	fdf->bres->ey = 0;
	fdf->bres->dy = 0;
	fdf->bres->Dy = 0;
	fdf->bres->yi = 0;
}

void	f_cam_zero(t_fdf *fdf)
{
	fdf->cam->angle = 0;
	fdf->cam->iso = 0;
	fdf->cam->zoom = 0;
	fdf->cam->offset_x = 0;
	fdf->cam->offset_y = 0;
	fdf->cam->offset_z = 0;
}

void	f_points_zero(t_fdf *fdf)
{
	fdf->points->x1 = 0;
	fdf->points->x2 = 0;
	fdf->points->y1 = 0;
	fdf->points->y2 = 0;
	fdf->points->z1 = 0;
	fdf->points->z2 = 0;
	fdf->points->p_x1 = 0;
	fdf->points->p_x2 = 0;
	fdf->points->p_y1 = 0;
	fdf->points->p_y2 = 0;
	fdf->points->p_z1 = 0;
	fdf->points->p_z2 = 0;
}

void	f_magic_board(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	f_fdf_zero(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	f_draw_line(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
}
