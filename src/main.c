/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/24 14:03:49 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main (int argc, char **argv)
{
	(void)argv;
	if (argc != 2 || f_check_fdf(argv[1]) == 0)
	{
		ft_printf ("\n🚨 "RED"Error :"WHT" Need an argument valid <name file>.fdf\n\n");
		return (0);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf ("\n🚨 "RED"Error :"WHT" Need an POPI argument <name file>.fdf\n\n");
		return (0);
	}
	// ft_printf("%s\n", get_next_line(fd));
	prerecup_data(fd);
	// close(fd);
	return (0);
}
