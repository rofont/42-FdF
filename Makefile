# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 10:43:15 by rofontai          #+#    #+#              #
#    Updated: 2023/05/19 11:07:41 by rofontai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define BANNER

     _$G/\/\/\/\/\/\$W__$G/\/\$W____$G/\/\$W______________$G/\/\$W__________________$G/\/\/\/\/\/\$W_________________________
    _$G/\/\$W__________________$G/\/\$W______________$G/\/\$W____$G/\/\/\$W________$G/\/\$W____________$G/\/\/\$W____$G/\/\$W__$G/\/\$W_
   _$G/\/\/\/\/\$W____$G/\/\$W____$G/\/\$W__________$G/\/\/\/\$W__$G/\/\/\/\/\$W______$G/\/\/\/\/\$W____$G/\/\/\/\/\$W__$G/\/\/\/\$W___
  _$G/\/\$W__________$G/\/\$W____$G/\/\$W________$G/\/\$W__$G/\/\$W__$G/\/\$W____________$G/\/\$W__________$G/\/\$W________$G/\/\$W_______
 _$G/\/\$W__________$G/\/\/\$W__$G/\/\/\$W________$G/\/\/\/\$W____$G/\/\/\/\$W______$G/\/\$W____________$G/\/\/\/\$W__$G/\/\$W_______

endef
export

# COLORS-----------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

# VARIABLES--------------------------------------------------------------------

NAME	= fdf
NAME_BONUS	= fdf_bonus

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address #-lm

SRC_DIR	= ./src
SRC		= main.c utils.c parse.c create_map.c \
			init_mlx.c draw_map.c utils_draw.c bresenham.c \

SRC_DIR_BONUS	= ./src_bonus
SRC_BONUS		= main_bonus.c utils_bonus.c parse_bonus.c create_map_bonus.c \
			init_mlx_bonus.c draw_map_bonus.c utils_draw_bonus.c bresenham_bonus.c \
			controls_bonus.c utils_zero_bonus.c controls_2_bonus.c controls_move_bonus.c \
			


OBJ_DIR	= ./obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR_BONUS	= ./obj_bonus
OBJ_BONUS		= $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))

LIB_MLX	= ./lib/MLX42
MLX		= $(LIB_MLX)/build/libmlx42.a
OS		= $(shell uname)
OS_PRO	= $(shell uname -p)
MAC_SCH	= -I /include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
MAC_PRO	= -I /include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"

HEAD_DIR 	=   ./include
HEADER      =   $(HEAD_DIR)/fdf.h
HEADER_BONUS	=   $(HEAD_DIR)/fdf_bonus.h


LIBFT_DIR	= ./lib/libft
LIBFT	= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ./lib/ft_printf
PRINTF	= $(PRINTF_DIR)/libftprintf.a

# CHECK OS---------------------------------------------------------------------

ifeq ($(OS_PRO), arm)
    FLAGS = $(MAC_PRO)
else ifeq ($(OS), Darwin)
    FLAGS = $(MAC_SCH)
endif

# ARGUMENTS--------------------------------------------------------------------

all	: $(NAME)
	@echo $G"$$BANNER"$W
	@echo "\n#-----$CFDF ready$W ✅---------------#\n"

$(MLX)	:
	@cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4

$(NAME)	:  $(MLX) $(OBJ_DIR) $(PRINTF) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(OBJ) $(MLX) $(FLAGS) -o $(NAME)


$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$G Compilation : $Z $(notdir $<)"$W

$(OBJ_DIR)	:
	@mkdir -p $@

$(PRINTF)	:
	@make -C $(PRINTF_DIR)

$(LIBFT)	:
	@make -C $(LIBFT_DIR)

 # BONNUS----------------------------------------------------------------------
bonus : $(NAME_BONUS)
	@echo $G"$$BANNER"$W
	@echo "\n#-----$CFDF_BONUS ready$W ✅---------------#\n"

$(NAME_BONUS)	:  $(MLX) $(OBJ_DIR_BONUS) $(PRINTF) $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(OBJ_BONUS) $(MLX) $(FLAGS) -o $(NAME_BONUS)


$(OBJ_DIR_BONUS)/%.o	:	$(SRC_DIR_BONUS)/%.c $(HEADER_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$G Compilation : $Z $(notdir $<)"$W

$(OBJ_DIR_BONUS)	:
	@mkdir -p $@

clean	:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
#	@rm -f $(OBJS)
#	@rm -rf $(LIB_MLX)/build
#	@rm -rf $(LIB_MLX)/CMakeCache.txt
	@echo "\n#-----$RMLX clean$W ❌---------------------#\n"
	@echo "\n#-----$RFDF clean$W ❌---------------------#\n"

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@echo "\n#-----$RFDF fclean$W ❌--------------------#\n"

re	:	fclean all

.PHONY	: all, mlx, clean, fclean, re, bonus

# DIVERS-----------------------------------------------------------------------

#gestino des couleurs : https://www.w3schools.com/css/css_colors_rgb.asp