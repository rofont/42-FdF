
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

typedef struct s_bres
{
	double	x1;
	double	x2;
	double	ex;
	double	dx;
	double	Dx;
	double	xi;
	double	y1;
	double	y2;
	double	ey;
	double	dy;
	double	Dy;
	double	yi;
}		t_bres;

typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
}		t_point;

typedef struct s_fdf
{
	int			x;
	int			y;
	int 		z;
	int			scale;
	int			height;
	int			width;
	t_point		*point;
	int			**map;
	t_bres		*bres;
	mlx_image_t	*img;
	mlx_t		*mlx;

}			t_fdf;

# define WIDTH 520
# define HEIGHT 520

// PARSE-----------------------------------------------------------------------

int		f_check_fdf(char *str);
void	f_check_arg(int argc, char **argv);

// CREATE_MAP------------------------------------------------------------------
int		count_collum(char *str, char c);
void	f_alloc_map(t_fdf *fdf);
void	f_size_map(t_fdf *fdf, char *file);
void	f_extract_point(t_fdf *fdf, char *line);
void	f_create_map(t_fdf *fdf, char *arg);

// UTILS-----------------------------------------------------------------------

t_fdf	*f_init_fdf(void);
void	f_cleanup(t_fdf *fdf, char *msg);
void	f_error(char *msg);
t_point	*f_init_point(void);
int 	get_rgba(int r, int g, int b, int a);

// UTILS_DRAW------------------------------------------------------------------

void f_modif_bres(t_bres *new);
void f_draw_x(t_fdf *fdf, int i, int color);
void f_draw_y(t_fdf *fdf, int i, int color);

// INIT_MLX--------------------------------------------------------------------

void f_init_mlx(t_fdf *fdf);
void draw_point(t_fdf *fdf);
void f_draw_line(t_fdf *fdf);
void f_map_scale(t_fdf *fdf);
void f_draw_line_x(t_fdf *fdf);
void f_draw_line_y(t_fdf *fdf);
void f_init_line_x(t_fdf *fdf);
void f_init_line_y(t_fdf *fdf);
void f_app_scale(t_fdf *fdf);
void f_start_point(t_fdf *fdf);

// DRAW------------------------------------------------------------------------

void f_bresenham(t_fdf *fdf, int color);
t_point *calc_isometric(t_point *pts, int max_pts);

// DELETE----------------------------------------------------------------------

void f_print_tabint(int **tab, int colum, int line);
void f_print_struct(t_fdf *fdf);
void f_print_point(t_fdf *fdf);

#endif
