/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:58:55 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/28 13:07:49 by rofontai         ###   ########.fr       */
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

void	f_size_map(t_fdf *fdf, char *file)
{
	char *line;
	int flag;
	int fd;

	fd =open(file, O_RDONLY);
	flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (flag == 0)
			fdf->width = count_collum(line, 32);
		free(line);
		fdf->height++;
		flag = 1;
	}
	close(fd);
}

void	f_alloc_map(t_fdf *fdf)
{
	int i;

	i = 0;
	fdf->map = ft_calloc(sizeof(int *), fdf->height);
	if (!fdf->map)
		return ;
	while (i < fdf->height)
	{
		fdf->map[i++] = ft_calloc(sizeof(int), fdf->width);
		if (!fdf->map)
			return ;
	}
}

void	f_extract_point(char *line, t_fdf *fdf)
{
	char		**lines;
	int			x;
	static int	y = 0;

	x = 0;
	lines = ft_split(line, 32);
	while (x < fdf->width)
	{
		fdf->map[y][x] = ft_atoi(lines[x]);
		x++;
	}
	y++;
	ft_free_tab_char(lines);
}

void	f_create_map(t_fdf *fdf, char *arg)
{
	char *line;
	int fd;

	f_size_map(fdf, arg);
	fd = open(arg, O_RDONLY);
	f_alloc_map(fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		f_extract_point(line, fdf);
		free(line);
	}
	close (fd);
}
