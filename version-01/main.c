#include <fcntl.h>
#include "fdf.h"
#include <mlx.h>
#include <libft.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_map	*map;
	int result;

	if (argc == 2)
	{
		//валидция и инициализация карты
		map = map_initialize(argv[1]);
		result = read_map(argv[1], map);
	}
	else
		print_error(ERR_USAGE);
	return (0);
}