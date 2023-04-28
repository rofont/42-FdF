/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/27 21:19:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int main (int argc, char **argv)
{
	t_map *fdf;
	mlx_t *mlx;


	fdf = f_init_fdf();
	f_check_arg(argc, argv);
	fdf = f_create_map(argv[1], fdf);
	f_print_tabint(fdf->tab, fdf->height, fdf->width);
	mlx = mlx_init(1080 , 1080, argv[1], true);
	if (!mlx)
	{
		fprintf(stderr, "%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	f_free_tabint(fdf->tab, fdf->height);
	free(fdf);
	return (0);
}
