/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:38:34 by rofontai          #+#    #+#             */
/*   Updated: 2022/11/22 08:32:19 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define TAB_BASE_HEX_U "0123456789ABCDEF"
# define TAB_BASE_HEX_L "0123456789abcdef"
# define TAB_BASE_DEC "0123456789"

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_arg_value(va_list arg, char c);
int	ft_printstr(char const *str);
int	ft_printbase(long n, char *tab_base, char c);
int	ft_printptr(void *ptr);

#endif
