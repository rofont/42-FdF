/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:10:57 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 22:19:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

t_fdf	*f_init_fdf(void)
{
	static t_fdf	*new;

	if (!new)
	{
		new = ft_calloc(sizeof(t_fdf), 1);
		if (!new)
			return (0);
		new->x = 0;
		new->y = 0;
		new->z = 0;
		new->height = 0;
		new->width = 0;
		new->scale = 0;
		new->cam = ft_calloc(sizeof(t_cam), 1);
		new->bres = ft_calloc(sizeof(t_bres), 1);
		new->points = ft_calloc(sizeof(t_point), 1);
		new->map = NULL;
	}
	return (new);
}

void	f_cleanup(t_fdf *fdf, char *msg)
{
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->points)
		free(fdf->points);
	if (fdf->bres)
		free(fdf->bres);
	if (fdf->map)
		ft_free_tab_int(fdf->map, fdf->height);
	if (fdf)
		free(fdf);
	if (msg)
		f_error(msg);
	if (!msg)
		exit(EXIT_SUCCESS);
}

void	f_error(char *msg)
{
	ft_printf("🚨 "RED" Error : "WHT" %s\n", msg);
	exit (EXIT_FAILURE);
}

void	f_fdf_zero(t_fdf *fdf)
{
		fdf->x = 0;
		fdf->y = 0;
		fdf->z = 0;
		// f_cam_zero(fdf);
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