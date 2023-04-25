/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/24 22:13:08 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main (int argc, char **argv)
{
	char **line;
	int i = 0;
	if (argc != 2 || f_check_fdf(argv[1]) == 0)
	{
		ft_printf ("\n🚨 "RED"Error :"WHT" Need an argument valid <name file>.fdf\n\n");
		return (0);
	}
	line = f_extract_line(argv[1]);
	while (line[i])
	{
		ft_printf ("%s", line[i]);
		free(line[i]);
		i++;
	}
	free(line);
	return (0);
}

