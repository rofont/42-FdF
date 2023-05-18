/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:03:11 by romain            #+#    #+#             */
/*   Updated: 2023/05/17 22:12:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*f_init_fdf(void)
{
	static t_fdf	*new;

	if (!new)
	{
		new = ft_calloc(sizeof(t_fdf), 1);
		if (!new)
			return (0);
		new->x = 0;
		new->y = 0;
		new->z = 0;
		new->height = 0;
		new->width = 0;
		new->scale = 0;
		new->start_x = 0;
		new->start_y = 0;
		new->view = f_init_view();
		new->bres = ft_calloc(sizeof(t_bres), 1);
		new->points = ft_calloc(sizeof(t_point), 1);
		new->map = NULL;
	}
	return (new);
}

t_view *f_init_view(void)
{
	static t_view	*new;

	if (!new)
	{
		new = ft_calloc(sizeof(t_view), 1);
		if (!new)
			return (0);
		new->offset_x = 1;
		new->offset_y = 1;
	}
	return (new);
}


void	f_error(char *msg)
{
	ft_printf("🚨 "RED" Error : "WHT" %s\n", msg);
	exit (EXIT_FAILURE);
}

void	f_cleanup(t_fdf *fdf, char *msg)
{
	if (fdf->points)
		free(fdf->points);
	if (fdf->bres)
		free(fdf->bres);
	if (fdf->view)
		free(fdf->view);
	if (fdf->map)
		ft_free_tab_int(fdf->map, fdf->height);
	if (fdf)
		free(fdf);
	if (msg)
		f_error(msg);
	if (!msg)
		exit(EXIT_SUCCESS);
}

void f_erase(t_fdf *fdf)
{
		fdf->x = 0;
		fdf->y = 0;
		fdf->z = 0;
		fdf->start_x = 0;
		fdf->start_y = 0;
		fdf->view = f_init_view();
		fdf->bres = ft_calloc(sizeof(t_bres), 1);
		fdf->points = ft_calloc(sizeof(t_point), 1);
}