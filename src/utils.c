/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:46:14 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/25 15:57:49 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//check si .fdf est bien a la fin du fichier
int f_check_fdf(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

// calculer la hauteur de la fenetre pour le malloc
int size_height(char *arg)
{
	int i;

	i = 0;
	int fd = open(arg, O_RDONLY);
	while (get_next_line(fd) != NULL)
		i++;
	close (fd);
	return (i);
}

//Fonction qui extrait les lignes des maps
char **f_extract_line(char *arg)
{
	char **temp;
	int x = 0;
	int size = size_height(arg);
	int fd = open(arg, O_RDONLY);
	if (fd < 0 || f_check_fdf(arg) == 0)
	{
		ft_printf ("\n🚨 "RED"Error :"WHT" bad file\n\n");
		return (0);
	}
	temp = ft_calloc(sizeof(char *), size +1);
	temp[x] = get_next_line(fd);
	while (temp[x])
	{
		x++;
		temp[x] =get_next_line(fd);
	}
	close (fd);
	return (temp);
}

//Fct qui split les espaces atoi de chaque petites arrays; et uqi les mets dans un tableau de int;
