
#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include "../lib/libft/include/get_next_line.h"
# include "../lib/ft_printf/include/ft_printf.h"

// COLOR-----------------------------------------------------------------------

# define BCK "\x1B[30m"
# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLE "\x1B[34m"
# define MAG "\x1B[35m"
# define CYA "\x1B[36m"
# define WHT "\x1B[37m"

// BRIGHT COLOR----------------------------------------------------------------

# define B_BCK "\x1B[90m"
# define B_RED "\x1B[91m"
# define B_GRE "\x1B[92m"
# define B_YEL "\x1B[93m"
# define B_BLE "\x1B[94m"
# define B_MAG "\x1B[95m"
# define B_CYA "\x1B[96m"
# define B_WHT "\x1B[97m"

// STRUCTURE-------------------------------------------------------------------

typedef struct s_map{
	int	**tab;
	int	height;
	int	width;
}			t_map;

// CHECK FILE------------------------------------------------------------------

void 	f_check_arg(int argc, char **argv);
int		f_check_fdf(char *str);

// CREATE_MAP------------------------------------------------------------------

t_map	*f_create_map(char *arg, t_map *map);
int 	*f_extract_line(char *line, t_map *map, int y);
t_map	*f_size_map(char *file);

// UTILS-----------------------------------------------------------------------

int		**f_free_tabint(int **map, int size);
char	**f_free_tab(char **tab);
void	f_print_tabint(int **tab, int colum, int line);
t_map	*f_init_fdf(void);

#endif

