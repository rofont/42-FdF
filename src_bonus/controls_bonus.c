/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:40:54 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 22:09:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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

void	f_move_right(t_fdf *fdf)
{
	fdf->cam->offset_x += 5;
	f_magic_board(fdf);
}
