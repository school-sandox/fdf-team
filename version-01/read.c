#include <stdio.h>
#include <libft.h>
#include "fdf.h"
#include <errno.h>
#include <fcntl.h>

int             read_map(const char *file, t_map *map)
{
    t_point     *points;
    int         fd;
    int         result;
    char        *str;
    char        **coordinates;

    fd = open(file, O_RDONLY);
    while((result = get_next_line(fd, &str)) == 1)
    {
        if (!(coordinates = ft_strsplit(str, ' ')))
            print_error(ERR_READ_MAP);
        //TODO - static void    parse_coords(char **coords, t_map *map); - реализовать
        free_coordinates(&coordinates);
        ft_strdel(&str);
    }
    close(fd);
    read_result(result);
    return result;
}

void			free_coordinates(char ***coordinates)
{
	int			i;

	i = 0;
	if (!(coordinates && *coordinates))
		return ;
	while ((*coordinates)[i])
	{
		ft_strdel(&(*coordinates)[i]);
		(*coordinates)[i++] = 0;
	}
	free(*coordinates);
	*coordinates = 0;
}

void    read_result(int result)
{
    result == -1 ? print_error(ERR_READ_MAP) : (void)'0';
}