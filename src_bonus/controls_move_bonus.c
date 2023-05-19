/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:51:55 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/19 10:52:40 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	f_move_right(t_fdf *fdf)
{
	fdf->cam->offset_x += 5;
	f_magic_board(fdf);
}

void	f_move_left(t_fdf *fdf)
{
	fdf->cam->offset_x -= 5;
	f_magic_board(fdf);
}

void	f_move_up(t_fdf *fdf)
{
	fdf->cam->offset_y -= 5;
	f_magic_board(fdf);
}

void	f_move_down(t_fdf *fdf)
{
	fdf->cam->offset_y += 5;
	f_magic_board(fdf);
}

void	f_rotate_angle(t_fdf *fdf)
{
	fdf->cam->angle += 0.01;
	f_magic_board(fdf);
}
