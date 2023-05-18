/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:52:29 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 20:31:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf *fdf;

	fdf = f_init_fdf();
	f_check_arg(argc, argv);
	f_create_map(fdf, argv[1]);
	f_mlx(fdf);
	// f_print_struct(fdf);
	// printf("of_x = %f\n", fdf->view->offset_x);
	// printf("of_y = %f\n", fdf->view->offset_y);

	// f_print_point(fdf);
	f_cleanup(fdf, NULL);
	return (0);
}