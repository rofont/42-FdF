/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:14:44 by romain            #+#    #+#             */
/*   Updated: 2023/05/01 08:24:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void f_init_mlx(t_fdf *fdf)
{
	mlx_t *mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "42-FdF", true);
	if (!mlx)
		f_cleanup(fdf, "error");
	mlx_loop(mlx);
	mlx_terminate(mlx);
}