/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/21 21:25:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main (int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_printf ("🚨 "RED"Error :"WHT" Need a argument <name file>.fdf\n");
	int fd = open(argv[1], O_RDONLY);
	ft_printf ("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}