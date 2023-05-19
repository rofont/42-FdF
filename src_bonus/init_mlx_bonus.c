/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:21:14 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 22:13:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	(void)keydata;
	fdf = (t_fdf *)param;
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_P))
		f_view_para(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_I))
		f_view_iso(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_RIGHT))
		f_move_right(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_LEFT))
	{
		fdf->cam->offset_x -= 5;
		f_magic_board(fdf);
	}
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_UP))
	{
		fdf->cam->offset_y -= 5;
		f_magic_board(fdf);
	}
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_DOWN))
	{
		fdf->cam->offset_y += 5;
		f_magic_board(fdf);
	}
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_W))
	{
		fdf->scale += 1;
		f_magic_board(fdf);
	}
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_S))
	{
		fdf->scale -= 1;
		f_magic_board(fdf);
	}

}

void	f_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "42-FdF", false);
	if (!fdf->mlx)
		f_cleanup(fdf, "error");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	f_draw_line(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	mlx_key_hook(fdf->mlx, &my_keyhook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}
