/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:07:03 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/27 10:46:36 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	**f_free_tabint(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**f_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

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
			x++;
		}
		ft_printf("\n");
		x= 0;
		y++;
	}
}

t_map	*f_init_fdf(void)
{
	t_map *new;

	new = ft_calloc(sizeof(t_map), 1);
	if (!new)
		return (0);
	new->height = 0;
	new->width = 0;
	new->tab = NULL;
	return (new);
}