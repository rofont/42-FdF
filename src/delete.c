/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:51:37 by rofontai          #+#    #+#             */
/*   Updated: 2023/05/11 09:49:14 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	ft_printf("scale = %d\n", fdf->scale);
	ft_printf("height = %d\n", fdf->height);
	ft_printf("width = %d\n", fdf->width);
	f_print_tabint(fdf->map, fdf->height, fdf->width);

}

void f_print_point(t_fdf *fdf)
{
	ft_printf("x1 = %d\n", fdf->bres->x1);
	ft_printf("y1 = %d\n", fdf->bres->y1);
	ft_printf("x2 = %d\n", fdf->bres->x2);
	ft_printf("y2 = %d\n", fdf->bres->y2);
	ft_printf("\n");
}