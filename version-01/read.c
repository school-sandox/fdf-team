#include "fdf.h"

static int			ft_charinstr(const char *str, char c)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (1);
	return (0);
}

void				points_filler(const char *str, t_map *map)
{
	char		**coordinates;
	char		**zandcolour;
	static int	i = 0;
	int			j;

	if (!(coordinates = ft_strsplit(str, ' ')))
		print_error(ERR_READ_MAP);
	j = 0;
	while (coordinates[j])
	{
		map->points[i].x = i / map->width;
		map->points[i].y = j;
		if (ft_charinstr((const char *)coordinates[j], ','))
		{
			zandcolour = ft_strsplit(coordinates[j], ',');
			map->points[i].z = ft_atoi(zandcolour[0]);
			map->points[i].colour = zandcolour[1]; //атойбэйс
		}
		else
		{
			map->points[i].z = ft_atoi(coordinates[j]);
			map->points[i].colour = NULL; //тест
		}
		//free_coordinates(&zandcolour);
		j++;
		i++;
	}
	free_coordinates(&coordinates);
}

int             read_map(const char *file, t_map *map)
{
    int         fd;
    int         result;
    char        *str;

    fd = open(file, O_RDONLY);
	map->points = (t_point *)malloc(sizeof(t_point) * map->size);
    while((result = get_next_line(fd, &str)) == 1)
    {
        points_filler((const char *)str, map);
        //TODO - static void    parse_coords(char **coords, t_map *map); - реализовать
        ft_strdel(&str);
    }
	for (int i = 0; i < map->size; i++)
			printf("x:%d y:%d z:%d colour:%s\n", map->points[i].x, map->points[i].y, map->points[i].z, map->points[i].colour);
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