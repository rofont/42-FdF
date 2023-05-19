/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:08:27 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 20:24:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = f_init_fdf();
	f_check_arg(argc, argv);
	f_create_map(fdf, argv[1]);
	f_scale(fdf);
	f_mlx(fdf);
	f_cleanup(fdf, NULL);
	return (0);
}
