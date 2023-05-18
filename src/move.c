/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:12:56 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 22:10:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_move(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		fdf->view->offset_x += 10;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		fdf->view->offset_x -= 10;
	else if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		fdf->view->offset_y -= 10;
	else if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		fdf->view->offset_y += 10;
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS) //TODO NON fonctionnel
		fdf->scale *= 10;
	f_draw_line(fdf);
}