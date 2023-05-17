/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:52:29 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 09:24:09 by rofontai         ###   ########.fr       */
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
	f_print_struct(fdf);
	// f_print_point(fdf);
	f_cleanup(fdf, NULL);
	return (0);
}