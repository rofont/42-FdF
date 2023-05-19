/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:21:14 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 19:55:19 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
