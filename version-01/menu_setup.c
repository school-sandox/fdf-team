#include "mlx.h"
#include "fdf.h"
#include "color.h"

static void	output(t_fdf *fdf, int x, int y, char **s)
{
	WRITE_STR(x, y, PINK_COLOR, *s);
	ft_strdel(s);
}

static void	controls_menu(t_fdf *fdf)
{
	WRITE_STR(15, 20, YELLOW_COLOR, "CONTROLS");
	WRITE_STR(15, 55, TEXT_COLOR, "Move:");
	WRITE_STR(85, 55, PINK_COLOR, "Arrows");
	WRITE_STR(155, 55, TEXT_COLOR, "|");
	WRITE_STR(175, 45, PINK_COLOR, "  W");
	WRITE_STR(175, 65, PINK_COLOR, "A S D");
	WRITE_STR(15, 95, TEXT_COLOR, "Zoom:");
	WRITE_STR(85, 95, PINK_COLOR, "Scroll");
	WRITE_STR(155, 92, TEXT_COLOR, "|");
	WRITE_STR(175, 95, PINK_COLOR, "+/-");
	WRITE_STR(15, 135, TEXT_COLOR, "Scale Z:");
	WRITE_STR(135, 135, PINK_COLOR, "<");
	WRITE_STR(155, 132, TEXT_COLOR, "|");
	WRITE_STR(175, 135, PINK_COLOR, ">");
	WRITE_STR(15, 210, TEXT_COLOR, "Rotate:");
	WRITE_STR(105, 170, PINK_COLOR, " U/J   I/K   O/L ");
	WRITE_STR(105, 190, TEXT_COLOR, " +   +   + ");
	WRITE_STR(105, 210, PINK_COLOR, "[X] [Y] [Z]");
}

static void	projection_menu(t_fdf *fdf)
{
	WRITE_STR(15, 325, YELLOW_COLOR, "PROJECTION");
	WRITE_STR(15, 360, TEXT_COLOR, "Horizontal:");
	WRITE_STR(155, 360, PINK_COLOR, "1");
	WRITE_STR(15, 390, TEXT_COLOR, "FRONT:");
	WRITE_STR(155, 390, PINK_COLOR, "2");
	WRITE_STR(15, 420, TEXT_COLOR, "CROSS:");
	WRITE_STR(155, 420, PINK_COLOR, "3");
	WRITE_STR(15, 450, TEXT_COLOR, "ISO:");
	WRITE_STR(155, 450, PINK_COLOR, "4");
}

void		setup_menu(t_fdf *fdf)
{
	controls_menu(fdf);
	projection_menu(fdf);
}