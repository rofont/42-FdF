
#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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

typedef struct s_point
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z1;
	double	z2;
	double	p_x1;
	double	p_x2;
	double	p_y1;
	double	p_y2;
	double	p_z1;
	double	p_z2;
}			t_point;

typedef struct s_bres
{
	double	ex;
	double	dx;
	double	Dx;
	double	xi;
	double	ey;
	double	dy;
	double	Dy;
	double	yi;
}		t_bres;

typedef struct s_cam
{
	int		offset_x;
	int		offset_y;
	double	offset_z;
	double	angle;
	int		zoom;
	int		iso;
	int 	colors;
}		t_cam;


typedef struct s_fdf
{
	int			x;
	int			y;
	int			z;
	int			scale;
	int			height;
	int			width;
	int			**map;
	t_cam		*cam;
	t_point		*points;
	t_bres		*bres;
	mlx_image_t	*img;
	mlx_t		*mlx;

}			t_fdf;

# define WIDTH 1080
# define HEIGHT 1080

// UTILS-----------------------------------------------------------------------

t_fdf	*f_init_fdf(void);
void	f_cleanup(t_fdf *fdf, char *msg);
void	f_error(char *msg);
void	f_menu(t_fdf *fdf);
void	f_change_rgba(t_fdf *fdf);

// UTILS_ZERO------------------------------------------------------------------

void	f_fdf_zero(t_fdf *fdf);
void	f_bres_zero(t_fdf *fdf);
void	f_points_zero(t_fdf *fdf);
void	f_magic_board(t_fdf *fdf);
void	f_cam_zero(t_fdf *fdf);

// PARSE-----------------------------------------------------------------------

int		f_check_fdf(char *str);
void	f_check_arg(int argc, char **argv);

// CREATE_MAP------------------------------------------------------------------

int		count_collum(char *str, char c);
void	f_size_map(t_fdf *fdf, char *file);
void	f_alloc_map(t_fdf *fdf);
void	f_extract_point(t_fdf *fdf, char *line);
void	f_create_map(t_fdf *fdf, char *arg);

// INIT_MLX--------------------------------------------------------------------

void	f_mlx(t_fdf *fdf);
void 	my_scrollhook(double xdelta, double ydelta, void* param);
void	my_hook_move(mlx_key_data_t keydata, t_fdf *fdf);
void	my_keyhook(mlx_key_data_t keydata, void *param);
int		get_rgba(int r, int g, int b, int a);

// DRAW_MAP--------------------------------------------------------------------

void	f_draw_line(t_fdf *fdf);
void	f_draw_line_x(t_fdf *fdf);
void	f_draw_line_y(t_fdf *fdf);
void	f_scale(t_fdf *fdf);
void	f_translate(t_fdf *fdf);

// UTILS_DRAW------------------------------------------------------------------

void 	f_init_line_x(t_fdf *fdf);
void 	f_init_line_y(t_fdf *fdf);
void 	f_app_scale(t_fdf *fdf);
void 	f_projection(t_fdf *fdf);
void 	f_start_point(t_fdf *fdf);

// BRESENHAM-------------------------------------------------------------------

void	f_modif_bres(t_fdf *fdf);
void	f_draw_x(t_fdf *fdf);
void	f_draw_y(t_fdf *fdf);
void 	f_bresenham(t_fdf *fdf);

// CONTROLS_MOVE---------------------------------------------------------------

void	f_move_right(t_fdf *fdf);
void	f_move_left(t_fdf *fdf);
void	f_move_up(t_fdf *fdf);
void	f_move_down(t_fdf *fdf);
void	f_rotate_angle_plus(t_fdf *fdf);

// CONTROLS--------------------------------------------------------------------

void	f_zoom_plus(t_fdf *fdf);
void	f_zoom_minus(t_fdf *fdf);
void	f_move_z_up(t_fdf *fdf);
void	f_move_z_down(t_fdf *fdf);

// CONTROLS_2------------------------------------------------------------------

void	f_return_start(t_fdf *fdf);
void	f_view_iso(t_fdf *fdf);
void	f_view_para(t_fdf *fdf);
void	f_rotate_angle_minus(t_fdf *fdf);


#endif