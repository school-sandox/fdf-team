/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:12:59 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 19:05:33 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		width_parser(char *str)
{
	int	nbrs;

	nbrs = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			++nbrs;
		while (ft_isdigit(*str))
			++str;
		if (*str == ',')
			while (*(str) != ' ' && *str)
				++str;
		while (!(ft_isdigit(*str)) && *str)
			++str;
	}
	return (nbrs);
}

static size_t	size_map(const char *file, t_map *map)
{
	int		width;
	int		height;
	char	*str;
	int		fd;

	width = 0;
	height = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(ERR_READ_MAP);
	while (get_next_line(fd, &str))
	{
		if (height == 0)
			map->width = width_parser(str);
		else if (width_parser(str) != map->width)
			print_error(ERR_MAP_INITIALIZE);
		height++;
		ft_strdel(&str);
	}
	map->height = height;
	if (!(map->height) && !(map->width))
		print_error(ERR_MAP_INITIALIZE);
	if (close(fd))
		print_error(ERR_READ_MAP);
	map->size = map->height * map->width;
	return (sizeof(t_point) * map->size);
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
	return (map);
}
