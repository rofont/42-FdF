/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:06:36 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/27 10:48:51 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
t_map *f_size_map(char *file)
{
	int fd;
	char *line;
	t_map *map;

	map = f_init_fdf();
	fd = open (file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->width = count_collum(line, 32);
		free(line);
		map->height++;
	}
	close (fd);
	return (map);
}

// creation de map.
int *f_extract_line(char *line, t_map *map, int y)
{
	char **lines;
	int x;

	x = 0;
	map->tab[y] = ft_calloc(sizeof(int), map->width);
	lines = ft_split(line, 32);
	while (x < map->width)
	{
		map->tab[y][x] = ft_atoi(lines[x]);

		x++;
	}
	f_free_tab(lines);
	return (map->tab[y]);
}

// lecture du fichier.
void f_create_map(char *arg, t_map *map)
{
	char *line;
	int fd;
	int y;

	y = 0;
	map = f_size_map(arg);
	map->tab = ft_calloc(sizeof(int *), map->height + 1);
	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		f_extract_line(line, map, y);
		y++;
		free(line);
	}
	f_print_tabint(map->tab, map->height, map->width);
	f_free_tabint(map->tab, map->height);
	free(map);
	close (fd);
}
