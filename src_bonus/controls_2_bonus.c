/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:55 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/19 13:11:02 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_return_start(t_fdf *fdf)
{
	f_cam_zero(fdf);
	f_magic_board(fdf);
}

void	f_view_iso(t_fdf *fdf)
{
	fdf->cam->iso = 0;
	f_magic_board(fdf);
}

void	f_view_para(t_fdf *fdf)
{
	fdf->cam->iso = 1;
	f_magic_board(fdf);
}

void	f_rotate_angle_minus(t_fdf *fdf)
{
	fdf->cam->angle -= 0.1;
	f_magic_board(fdf);
}
