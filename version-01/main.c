#include <fcntl.h>
#include "fdf.h"
#include <mlx.h>
#include <libft.h>
#include <stdio.h>

void		print_error(char *message)
{
		ft_putendl_fd(message, 2);
	    exit(1);
}

int			main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	*fdf;

	if (argc == 2)
	{
		//валидция и инициализация карты
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