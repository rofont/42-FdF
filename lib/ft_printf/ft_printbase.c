/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:41:34 by rofontai          #+#    #+#             */
/*   Updated: 2023/04/20 13:25:27 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static long	ft_print_nb(long n, char c, long temp)
{
	if (n > 9)
	{
		if (c == 'x')
			temp += ft_printchar(n + 87);
		else if (c == 'X')
			temp += ft_printchar(n + 55);
	}
	else
		temp += ft_printchar(n + 48);
	return (temp);
}

int	ft_printbase(long n, char *tab_base, char c)
{
	long	temp;
	int		base;

	temp = 0;
	base = ft_strlen(tab_base);
	if (n < 0 && base <= 10)
	{
		temp += ft_printchar('-');
		n *= -1;
	}
	if (n >= base)
	{
		temp += ft_printbase((n / base), tab_base, c);
		temp += ft_printbase((n % base), tab_base, c);
	}
	else
		temp = ft_print_nb(n, c, temp);
	return (temp);
}
