/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:32 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/26 07:59:20 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main (int argc, char **argv)
{
	char **line;
	int i;
	int j = 0;
	if (argc != 2)
	{
		ft_printf ("\n🚨 "RED"Error :"WHT" Need an argument valid <name file>.fdf\n\n");
		return (0);
	}
	i = size_height(argv[1]);
	// ft_printf("nombre de ligne %d\n", i);
	line = f_extract_line(argv[1]);
	while (j < i)
	{
		ft_printf ("%s", line[j]);
		free(line[j]);
		j++;
	}
	free(line);
	return (0);
}
