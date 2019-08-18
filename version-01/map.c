#include <stdio.h>
#include <libft.h>
#include "fdf.h"
#include <errno.h>
#include <fcntl.h>

static int        width_parser(char *str)
{
    int	nbrs;

    nbrs = 0;
    while (*str)
    {
        if (ft_isdigit(*str))
            nbrs++;
        while (ft_isdigit(*str))
            str++;
        if (*str == ',')
            while (*(++str) != ' ' && *str);
        while (!(ft_isdigit(*str)) && *str)
            str++;
    }
    return (nbrs);
}

static size_t size_map(const char *file, t_map *map){
    int width = 0;
    int height = 0;
    char *str;
    int fd;

    fd = open(file, O_RDONLY);

    while(get_next_line(fd, &str))
    {
        if(height == 0)
        {
            map->width = width_parser(str);
        }
        else if (width_parser(str) != map->width){
            print_error(ERR_MAP_INITIALIZE);
        }
        height++;
        ft_strdel(&str);
    }
    map->height = height;
    close(fd);
    map->size = map->height * map->width;
    //printf("width %d\n", map->width);
    //printf("height %d\n", map->height);
    //printf("size %d\n", map->size);
    return (sizeof(t_point) * map->size);;
}

t_map			*map_initialize(const char *file)
{
	t_map		*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		print_error(ERR_MALLOC_MAP_INITIALIZE);
	if (!(map->points = (t_point *)malloc(size_map(file, map))))
		print_error(ERR_MALLOC_MAP_INITIALIZE);
	map->z_min = MAX_INT;
	map->z_max = MIN_INT;

    //printf("map->z_min %d\n", map->z_min);
    //printf("map->z_max %d\n", map->z_max);
	return (map);
}
