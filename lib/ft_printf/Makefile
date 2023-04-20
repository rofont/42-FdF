# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:36:23 by rofontai          #+#    #+#              #
#    Updated: 2023/04/20 14:06:42 by rofontai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c 		\
		ft_printbase.c 	\
		ft_printchar.c	\
		ft_printstr.c	\
		ft_arg_value.c	\
		ft_printptr.c	\

OBJ = ${SRC:.c=.o}

CC   = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	@ar -rcs  ${NAME} ${OBJ}
	@echo "$G Compilation : $Z $<"$W

clean:
	@rm -rf ${OBJ}
	@echo "\n#-----$RFT_PRINTF clean$W ❌---------------#\n"

fclean: clean
	@rm -f ${NAME}
	@echo "nettoyage poussé"

re: fclean all

.PHONY: all clean fclean re