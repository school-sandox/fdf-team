#include "fdf.h"
#include "mlx.h"
#include "keys.h"



int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS || key == MAIN_PAD_0
		|| key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == MAIN_PAD_A
		|| key == ARROW_RIGHT || key == MAIN_PAD_D
		|| key == ARROW_UP || key == MAIN_PAD_W
		|| key == ARROW_DOWN || key == MAIN_PAD_S)
		move(key, fdf);
	else if (key == MAIN_PAD_J || key == MAIN_PAD_U
		|| key == MAIN_PAD_K || key == MAIN_PAD_I
		|| key == MAIN_PAD_L || key == MAIN_PAD_O)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		scale(key, fdf);
	else if (key == MAIN_PAD_1 || key == NUM_PAD_1
		|| key == MAIN_PAD_2 || key == NUM_PAD_2
		|| key == MAIN_PAD_3 || key == NUM_PAD_3
		|| key == MAIN_PAD_4 || key == NUM_PAD_4)
		change_projection(key, fdf);
	return (0);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = TRUE;
	return (0);
}

int			mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = FALSE;
	return (0);
}

int			mouse_m(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		print_map(fdf->map, fdf);
	}
	return (0);
}

int			close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	setup_control(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_m, fdf);
}