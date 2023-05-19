/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:40:54 by romain            #+#    #+#             */
/*   Updated: 2023/05/19 12:44:50 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_zoom_plus(t_fdf *fdf)
{
	fdf->cam->zoom += 1;
	f_magic_board(fdf);
}

void	f_zoom_minus(t_fdf *fdf)
{
	fdf->cam->zoom -= 1;
	f_magic_board(fdf);
}

void	f_move_z_up(t_fdf *fdf)
{
	fdf->cam->offset_z += 1;
	f_magic_board(fdf);
}

void	f_move_z_down(t_fdf *fdf)
{
	fdf->cam->offset_z -= 1;
	f_magic_board(fdf);
}
