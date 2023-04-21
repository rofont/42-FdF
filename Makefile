# NAME	:= Game
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./lib/MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
# SRCS	:= ./src/main_test2.c
# #$(shell find ./src -iname "*.c")
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -f $(OBJS)
# 	@rm -f $(LIBMLX)/build

# fclean: clean
# 	@rm -f $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx

# BANNER-----------------------------------------------------------------------

define BANNER

     _$G/\/\/\/\/\/\$W__$G/\/\$W____$G/\/\$W______________$G/\/\$W__________________$G/\/\/\/\/\/\$W_________________________
    _$G/\/\$W__________________$G/\/\$W______________$G/\/\$W____$G/\/\/\$W________$G/\/\$W____________$G/\/\/\$W____$G/\/\$W__$G/\/\$W_
   _$G/\/\/\/\/\$W____$G/\/\$W____$G/\/\$W__________$G/\/\/\/\$W__$G/\/\/\/\/\$W______$G/\/\/\/\/\$W____$G/\/\/\/\/\$W__$G/\/\/\/\$W___
  _$G/\/\$W__________$G/\/\$W____$G/\/\$W________$G/\/\$W__$G/\/\$W__$G/\/\$W____________$G/\/\$W__________$G/\/\$W________$G/\/\$W_______
 _$G/\/\$W__________$G/\/\/\$W__$G/\/\/\$W________$G/\/\/\/\$W____$G/\/\/\/\$W______$G/\/\$W____________$G/\/\/\/\$W__$G/\/\$W_______
____________________________________________________________________________________________________

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

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g #-lm

SRC_DIR	= ./src
SRC		= main_test2.c

OBJ_DIR	= ./obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIB_MLX	= ./lib/MLX42
MLX		= $(LIB_MLX)/build/libmlx42.a
OS		= $(shell uname)
OS_PRO	= $(shell uname -p)
MAC_SCH	= -I /include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
MAC_PRO	= -I /include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib"

HEAD_DIR 	=   ./include
HEADER      =   $(HEAD_DIR)/fdf.h

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

mlx	:
	@cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4

$(NAME)	:	mlx $(OBJ_DIR) $(PRINTF) $(LIBFT) $(OBJ)
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

clean	:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
#	@rm -rf $(LIB_MLX)/build
#	@echo "\n#-----$RMLX clean$W ❌---------------------#\n"
	@echo "\n#-----$RFDF clean$W ❌---------------------#\n"

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@echo "\n#-----$RFDF fclean$W ❌--------------------#\n"

re	:	clean all

.PHONY	: all, mlx, clean, fclean, re