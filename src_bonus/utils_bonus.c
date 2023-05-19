/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:10:57 by romain            #+#    #+#             */
/*   Updated: 2023/05/19 15:09:07 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
		new->cam = ft_calloc(sizeof(t_cam), 1);
		new->bres = ft_calloc(sizeof(t_bres), 1);
		new->points = ft_calloc(sizeof(t_point), 1);
		new->map = NULL;
	}
	return (new);
}

void	f_cleanup(t_fdf *fdf, char *msg)
{
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->points)
		free(fdf->points);
	if (fdf->bres)
		free(fdf->bres);
	if (fdf->map)
		ft_free_tab_int(fdf->map, fdf->height);
	if (fdf)
		free(fdf);
	if (msg)
		f_error(msg);
	if (!msg)
		exit(EXIT_SUCCESS);
}

void	f_error(char *msg)
{
	ft_printf("🚨 "RED" Error : "WHT" %s\n", msg);
	exit (EXIT_FAILURE);
}

void	f_menu(t_fdf *fdf)
{
	(void)fdf;
	ft_printf("\n");
	ft_printf(" ----- "MAG"MENU 🗺"WHT"  ----- \n");
	ft_printf("\n");
	ft_printf("↑ = up\n");
	ft_printf("↓ = down\n");
	ft_printf("← = left\n");
	ft_printf("→ = right\n");
	ft_printf("p = view parallel\n");
	ft_printf("i = view isometric\n");
	ft_printf("w = zoom +\n");
	ft_printf("s = zoom -\n");
	ft_printf("r = angle +\n");
	ft_printf("t = angle -\n");
	ft_printf("z = z value +\n");
	ft_printf("x = z value -\n");
	ft_printf("space = re init value\n");
	ft_printf("\n");
	ft_printf(" --- "MAG"SCROLL_MOUSE 🖱"WHT" --- \n");
	ft_printf("\n");
	ft_printf("🔼 = zoom +\n");
	ft_printf("🔽 = zoom -\n");
	ft_printf("\n");
}

void	f_change_rgba(t_fdf *fdf)
{
	if ((fdf->points->z1 * fdf->cam->offset_z) > 5
		|| (fdf->points->z2 * fdf->cam->offset_z) > 5)
		fdf->cam->colors = get_rgba(99, 255, 219, 100);
	else if ((fdf->points->z1 * fdf->cam->offset_z) <= 0)
		fdf->cam->colors = get_rgba(255, 142, 255, 100);
}
