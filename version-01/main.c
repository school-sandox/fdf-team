/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:10:08 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 19:10:15 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	*fdf;

	if (argc == 2)
	{
		map = map_initialize(argv[1]);
		read_map(argv[1], map);
		fdf = fdf_initialize(map);
		fdf->camera = camera_initialize(fdf);
		print_map(map, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		print_error(ERR_USAGE);
	return (0);
}
