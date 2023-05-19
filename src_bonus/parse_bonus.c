/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:13:09 by romain            #+#    #+#             */
/*   Updated: 2023/05/18 20:25:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	f_check_fdf(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

void	f_check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		f_error("Need an argument valid <name file>.fdf");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || f_check_fdf(argv[1]) == 0)
		{
			close (fd);
			f_error("Need a valid file <name file>.fdf");
		}
	}
}
