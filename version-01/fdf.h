#ifndef FDF_H
#define FDF_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERR_USAGE   "Usage: ./fdf <name-file.fdf>"
# define ERR_MALLOC_MAP_INITIALIZE "Malloc map_initialize Error."
# define ERR_MAP_INITIALIZE "Invalid Map. Check your map."
# define ERR_READ_MAP "Reading fail"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <libft.h>

typedef struct			s_point{
	int		x;
	int		y;
	int		z;
	int		colour;
}						t_point;

typedef struct			s_map{
	void* mlx_ptr;
	void* win_ptr;
	int width;
	int height;
	int size;
	int z_max;
	int z_min;
	t_point *points;
}						t_map;

t_map					*map_initialize(const char *file);
void					print_error(char *message);
int						read_map(const char *file, t_map *map);
void					read_result(int result);
void					free_coordinates(char ***coordinates);
int						ft_atoi_hex(const char *str);


#endif