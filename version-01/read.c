/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:10:40 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/18 22:54:16 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_chrstr(const char *str, char c)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (1);
	return (0);
}

static int		ft_chrnstr(const char *str, char c, int n)
{
	int i;

	i = -1;
	while (str[++i] != '\0' && i < n)
		if (str[i] == c)
			return (1);
	return (0);
}

static int		nbr_checker(const char *str, int base)
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

static void			points_parser(t_map *map, char **coords)
{
	char		**coord_zc;
	static int	i = 0;

	while (*coords)
	{
		coord_zc = NULL;
		map->points[i].x = i % map->width;
		map->points[i].y = i / map->width;
		if (ft_chrstr((const char *)*coords, ','))
		{
			if (!(coord_zc = ft_strsplit(*coords, ',')))
				print_error(ERR_READ_MAP);
			if (!(nbr_checker(coord_zc[0], 10)) || !(nbr_checker(coord_zc[1], 16)))
				print_error(ERR_HEX);
		}
		else
		{
			if (!(nbr_checker(*coords, 10)))
				print_error(ERR_HEX);
		}
		map->points[i].z = coord_zc ? ft_atoi(coord_zc[0]) : ft_atoi(*coords);
		map->points[i].colour = coord_zc ? ft_atoi_hex(coord_zc[1]) : 0; //не ноль
		++coords;
		++i;
		free_coordinates(&coord_zc);
	}
}

int				read_map(const char *file, t_map *map)
{
	int			fd;
	int			result;
	char		*str;
	char		**coords;

	fd = open(file, O_RDONLY);
	map->points = (t_point *)malloc(sizeof(t_point) * map->size);
	while ((result = get_next_line(fd, &str)) == 1)
	{
		if (!(coords = ft_strsplit(str, ' ')))
			print_error(ERR_READ_MAP);
		points_parser(map, coords);
		free_coordinates(&coords);
		ft_strdel(&str);
	}
	for (int i = 0; i < map->size; i++)
			printf("x:%d y:%d z:%d colour:%d\n", map->points[i].x, map->points[i].y, map->points[i].z, map->points[i].colour);
	close(fd);
	read_result(result);
	return (result);
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

void		read_result(int result)
{
	result == -1 ? print_error(ERR_READ_MAP) : (void)'0';
}
