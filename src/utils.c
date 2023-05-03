/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:05:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/03 15:11:44 by romain           ###   ########.fr       */
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
		new->height = 0;
		new->width = 0;
		new->scale = 50;
		new->map = NULL;
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
	if (fdf->map)
		ft_free_tab_int(fdf->map, fdf->height);
	if (fdf)
		free(fdf);
	if (msg)
		f_error(msg);
	if (!msg)
		exit(EXIT_SUCCESS);
}

//TODO A enlever
void f_print_tabint(int **tab, int colum, int line)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < colum)
	{
		while (x < line)
		{
			ft_printf("%d", tab[y][x]);
			ft_printf("  ");
			x++;
		}
		ft_printf("\n");
		x= 0;
		y++;
	}
}

//TODO A enlever
void f_print_struct(t_fdf *fdf)
{
	ft_printf("x = %d\n", fdf->x);
	ft_printf("y = %d\n", fdf->y);
	ft_printf("height = %d\n", fdf->height);
	ft_printf("width = %d\n", fdf->width);
	f_print_tabint(fdf->map, fdf->height, fdf->width);
}