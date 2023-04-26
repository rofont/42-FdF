/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:46:14 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/26 09:04:37 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//check .fdf
int	f_check_fdf(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

//Check_file
void	f_check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf ("🚨 "RED"Error :"WHT"\n");
		ft_printf("Need an argument valid <name file>.fdf\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || f_check_fdf(argv[1]) == 0)
	{
		ft_printf ("🚨 "RED"Error :"WHT"\n");
		ft_printf("Need a file valid <name file>.fdf\n");
		exit(EXIT_FAILURE);
	}
}
