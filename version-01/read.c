#include <stdio.h>
#include <libft.h>
#include "fdf.h"
#include <errno.h>
#include <fcntl.h>

int read_map(const char *file, t_map *map)
{
    t_point *points;
    int fd;
    int result;
    char *str;
    char **coordinates;

    fd = open(file, O_RDONLY);
    while((result = get_next_line(fd, &str)) == 1)
    {
        if (!(coordinates = ft_strsplit(str, ' ')))
            print_error(ERR_READ_MAP);
        //TODO - parse_string(char **string, t_map map);
        //TODO - free_coordinates(&str);
        ft_strdel(&str);
    }
    close(fd);
    return result;
}