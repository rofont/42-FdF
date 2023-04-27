/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/27 10:49:07 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main (int argc, char **argv)
{
	t_map *fdf;

	fdf = f_init_fdf();
	f_check_arg(argc, argv);
	f_create_map(argv[1], fdf);

	free(fdf);
	return (0);
}
