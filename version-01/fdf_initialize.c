#include "fdf.h"
#include <mlx.h>

t_fdf		*fdf_initialize(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		print_error(ERR_FDF_INIT);
	if (!(fdf->mlx_ptr = mlx_init()))
		print_error(ERR_FDF_INIT);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FdF")))
		print_error(ERR_FDF_INIT);
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		print_error(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	if (!(fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		print_error(ERR_FDF_INIT);
	return (fdf);
}