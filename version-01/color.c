#include "fdf.h"
#include "color.h"

static double	percentage(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				get_color(t_point current, t_point a, t_point b, t_point delta)
{
	double		percent;

	if (current.colour == b.colour)
		return (current.colour);
	if (delta.x > delta.y)
		percent = percentage(a.x, b.x, current.x);
	else
		percent = percentage(a.y, b.y, current.y);
	return (MERGE_RGB(NEW_LIGHT(GET_RED(a.colour), GET_RED(b.colour), percent),
					NEW_LIGHT(GET_GREEN(a.colour), GET_GREEN(b.colour), percent),
					NEW_LIGHT(GET_BLUE(a.colour), GET_BLUE(b.colour), percent)));
}

void			set_default_colors(t_map *map)
{
	int			i;
	double		percent;

	i = 0;
	while (i < map->size)
	{
		if (map->points[i].colour == -1)
		{
			percent = percentage(map->z_min, map->z_max, map->points[i].z);
		}
		i++;
	}
}
