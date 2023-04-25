/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:46:14 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/24 22:15:12 by romain           ###   ########.fr       */
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

//TODO Fonction qui extrait les lignes des maps dans une grandes arrays (open, GNL, join)
char **f_extract_line(char *arg)
{
	char **temp;
	int x = 0;
	int fd = open(arg, O_RDONLY);
	if (fd <= 0)
	{
		//TODO seg_fault en cas d'erreur
		ft_printf ("\n🚨 "RED"Error :"WHT" read file\n\n");
		return (0);
	}
	temp = ft_calloc(sizeof(char *), 10000); //TODO gestion de la taille du malloc en focntion de la map
	temp[x] = get_next_line(fd);
	while (temp[x])
	{
		x++;
		temp[x] =get_next_line(fd);
	}
	close (fd);
	return (temp);
}

//Fct qui split avec les \n de la grande arrays;
//Fct qui split les espaces atoi de chaque petites arrays; et uqi les mets dans un tableau de int;
