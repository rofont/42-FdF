/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 07:46:14 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/24 14:26:30 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int f_check_fdf(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

void prerecup_data(int fd)
{
	char **recup;
	int y;

	// y = 0;
	// while (get_next_line(fd))
	// 	y++;
	recup = ft_calloc(sizeof(char *), 1000);
	if (!recup)
		return ;
	y = 0;
	recup[y] = get_next_line(fd);
	ft_printf("hors de la while %s\n", recup[y]);
	while (recup[y++] != NULL)
	{
		recup[y] = get_next_line(fd);
		ft_printf(" dans la while %s\n", recup[y]);
	}
	// return (recup);
}
