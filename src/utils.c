/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:05:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/12 09:43:11 by rofontai         ###   ########.fr       */
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
		new->bres = ft_calloc(sizeof(t_bres), 1);
		new->map = NULL;
	}
	return (new);
}

t_point *f_init_point(void)
{
	t_point *new;

	new = ft_calloc(sizeof(t_point), 1);
	if (!new)
		return (0);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	// new->color = get_rgba(240, 240, 240, 1);

	return (new);
}

void	f_error(char *msg)
{
	ft_printf("🚨 "RED" Error : "WHT" %s\n", msg);
	exit (EXIT_FAILURE);
}

void	f_cleanup(t_fdf *fdf, char *msg)
{
	if (fdf->map)
		ft_free_tab_int(fdf->map, fdf->height);
	if (fdf)
		free(fdf);
	if (msg)
		f_error(msg);
	if (!msg)
		exit(EXIT_SUCCESS);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}