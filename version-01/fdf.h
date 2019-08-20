#ifndef FDF_H
#define FDF_H

# define ZOOM_WIDTH			(WIDTH - MENU_WIDTH) / fdf->map->width / 2
# define ZOOM_HEIGHT		HEIGHT / fdf->map->height / 2

# define WRITE_STR(x, y, c, s)	(mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, c, s))
# define TRUE				1
# define FALSE				0
# define FT_MIN(a, b)		(((a) < (b)) ? (a) : (b))
# define FT_ABS(x) 			(((x) < 0) ? (-(x)) : (x))
# define DEF_ZOOM(fdf)		FT_MIN(ZOOM_WIDTH, ZOOM_HEIGHT)
# define MENU_WIDTH			300
# define WIDTH				1440
# define HEIGHT				810
# define BACKGROUND			0xC0C0C0
# define MENU_BACKGROUND	0xC0C0C0
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERR_USAGE   "Usage: ./fdf <name-file.fdf>"
# define ERR_MALLOC_MAP_INITIALIZE "Malloc map_initialize Error."
# define ERR_MAP_INITIALIZE "Invalid Map. Check your map."
# define ERR_READ_MAP "Reading fail"
# define ERR_HEX "Hex error"
# define ERR_FDF_INIT "FDF initialiation error. Maybe smth wrong with mlx..."
# define ERR_CAMERA_INIT "Camere initialization fail."
# include <errno.h>
# include <fcntl.h>
# include <stdio.h> //delete
# include <libft.h>

typedef enum
{
	HORIZONTAL,
	FRONT,
	CROSS,
	ISO
}	t_projection;

typedef struct			s_mouse
{
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
	char				is_pressed;
}						t_mouse;


typedef struct			s_camera
{
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divider;
	int					x_offset;
	int					y_offset;
	t_projection		projection;
}						t_camera;

typedef struct			s_point{
	int		x;
	int		y;
	int		z;
	int		colour;
}						t_point;

typedef struct			s_map{
	int width;
	int height;
	int size;
	int z_max;
	int z_min;
	t_point *points;
}						t_map;

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
	t_mouse				*mouse;
}						t_fdf;

t_map					*map_initialize(const char *file);
void					print_error(char *message);
int						read_map(const char *file, t_map *map);
void					read_result(int result);
void					free_coordinates(char ***coordinates);
int						ft_atoi_hex(const char *str);
t_fdf					*fdf_initialize(t_map *map);
t_camera				*camera_initialize(t_fdf *fdf);
t_point					projection(t_point point, t_fdf *fdf);
void					print_map(t_map *map, t_fdf *fdf);
void					set_default_colors(t_map *map);


#endif