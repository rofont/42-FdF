/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:52:48 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/20 13:25:15 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	ft_arg_value(va_list arg, char c)
{
	int	temp;

	temp = 0;
	if (c == '%')
		temp += ft_printchar(c);
	else if (c == 'c')
		temp += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		temp += ft_printstr(va_arg(arg, char *));
	else if (c == 'i' || c == 'd')
		temp += ft_printbase((va_arg(arg, int)), TAB_BASE_DEC, c);
	else if (c == 'u')
		temp += ft_printbase((va_arg(arg, unsigned int)), TAB_BASE_DEC, c);
	else if (c == 'x')
		temp += ft_printbase((va_arg(arg, unsigned int)), TAB_BASE_HEX_L, c);
	else if (c == 'X')
		temp += ft_printbase(va_arg(arg, unsigned int), TAB_BASE_HEX_U, c);
	else if (c == 'p')
		temp += ft_printptr(va_arg(arg, void *));
	return (temp);
}
