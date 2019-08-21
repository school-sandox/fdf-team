/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:10:40 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 19:12:51 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			nbr_checker(const char *str, int base)
{
	int i;

	i = 0;
	if (base == 16)
	{
		if (str[0] != '0' || str[1] != 'x' || ft_strlen(str) > 8 ||
														ft_strlen(str) <= 2)
			return (0);
		i += 2;
	}
	else if (base == 10)
		if (str[0] == '-')
			i += 1;
	while (str[i])
	{
		if (!(ft_chrnstr("0123456789aAbBcCdDeEfF", str[i], base > 10 ?
													base * 2 - 10 : base)))
			return (0);
		++i;
	}
	return (1);
}

static void			free_coordinates(char ***coordinates)
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

static void			points_parser(t_map *map, char **coords)
{
	char		**coord_zc;
	static int	i = 0;

	while (*coords)
	{
		coord_zc = NULL;
		map->points[i].x = i % map->width;
		map->points[i].y = i / map->width;
		if (!(coord_zc = ft_strsplit(*coords, ',')))
			print_error(ERR_READ_MAP);
		if (ft_count(coord_zc) > 2)
			print_error(ERR_MAP_INITIALIZE);
		if (coord_zc[0] && !(nbr_checker(coord_zc[0], 10)))
			print_error(ERR_MAP_INITIALIZE);
		if (coord_zc[1] && !(nbr_checker(coord_zc[1], 16)))
			print_error(ERR_MAP_INITIALIZE);
		map->points[i].z = ft_atoi(coord_zc[0]);
		map->points[i].colour = coord_zc[1] ?
							ft_atoi_hex(coord_zc[1]) : 16777215;
		++coords;
		++i;
		free_coordinates(&coord_zc);
	}
}

int					read_map(const char *file, t_map *map)
{
	int			fd;
	int			result;
	char		*str;
	char		**coords;

	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(ERR_READ_MAP);
	while ((result = get_next_line(fd, &str)) == 1)
	{
		if (!(coords = ft_strsplit(str, ' ')))
			print_error(ERR_READ_MAP);
		points_parser(map, coords);
		free_coordinates(&coords);
		ft_strdel(&str);
	}
	if (close(fd))
		print_error(ERR_READ_MAP);
	result == -1 ? print_error(ERR_READ_MAP) : result;
	return (result);
}
