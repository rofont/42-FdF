/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:01:04 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/03 15:08:50 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = f_init_fdf();
	f_check_arg(argc, argv);
	f_create_map(fdf, argv[1]);
	f_print_struct(fdf);
	f_init_mlx(fdf);

	// print les lignes entre les points
	// faire la vue iso
	// et implementer les mouv
	f_cleanup(fdf, NULL);
	return (0);
}