/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:06:36 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/26 15:01:12 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	**free_tabint(int **tab, t_map map)
{
	int	i;

	i = 0;
	while (i < map.y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static char	**free_tab(char **tab)
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



static int	count_collum(char *str, char c)
{
	int	i;
	int	nbw;

	i = 0;
	nbw = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == c) && str[i])
			i++;
		while ((str[i] != c) && str[i])
			i++;
		if (str[i - 1] != c)
			nbw++;
	}
	return (nbw);
}

// taille de la map
t_map f_size_map(char *file)
{
	int fd;
	char *line;
	t_map map;

	map.x = 0;
	map.y = 0;
	fd = open (file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map.x = count_collum(line, 32);
		free(line);
		map.y++;
	}
	close (fd);
	return (map);
}


// creation de map.
int *f_create_map(char *line, int **tab, t_map map, int y)
{
	char **lines;
	int x;

	x = 0;
	tab[y] = ft_calloc(sizeof(int), map.x +1);
	lines = ft_split(line, 32);
	while (x < map.x)
	{
		tab[y][x] = ft_atoi(lines[x]);
		// ft_printf("%d", tab[y][x]);
		x++;
	}
	// ft_printf("\n");
	lines = free_tab(lines);
	// ft_print_tabint(tab, map.y, map.x);
	return (tab[y]);
}

// lecture du fichier.
void f_extract_line(char *arg)
{
	char *line;
	int fd;
	int **tab;
	t_map map;
	int y;

	y = 0;
	map = f_size_map(arg);
	tab = ft_calloc(sizeof(int *), map.y + 1);
	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		f_create_map(line, tab, map, y);
		y++;
		free(line);
	}
	ft_print_tabint(tab, map.y, map.x);
	tab = free_tabint(tab, map);
	close (fd);
}



void ft_print_tabint(int **tab, int colum, int line)
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
