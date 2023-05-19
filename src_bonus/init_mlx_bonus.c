/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:21:14 by romain            #+#    #+#             */
/*   Updated: 2023/05/19 12:49:09 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	(void)xdelta;
	fdf = (t_fdf *)param;
	if (ydelta > 0)
		f_zoom_plus(fdf);
	else if (ydelta < 0)
		f_zoom_minus(fdf);
}

void	my_hook_move(mlx_key_data_t keydata, t_fdf *fdf)
{
	(void)keydata;
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_RIGHT))
		f_move_right(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_LEFT))
		f_move_left(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_UP))
		f_move_up(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_DOWN))
		f_move_down(fdf);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	(void)keydata;
	fdf = (t_fdf *)param;
	my_hook_move(keydata, fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_P))
		f_view_para(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_I))
		f_view_iso(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_W))
		f_zoom_plus(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_S))
		f_zoom_minus(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_R))
		f_rotate_angle_plus(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_T))
		f_rotate_angle_minus(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_Z))
		f_move_z_up(fdf);
	if (mlx_is_key_down (fdf->mlx, MLX_KEY_X))
		f_move_z_down(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE))
		f_return_start(fdf);
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
	mlx_scroll_hook(fdf->mlx, &my_scrollhook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}
