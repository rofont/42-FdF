/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:21:24 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/20 13:25:39 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nb += ft_arg_value(args, str[i + 1]);
			i++;
		}
		else
			nb += ft_printchar(str[i]);
		i++;
	}
	va_end (args);
	return (nb);
}
