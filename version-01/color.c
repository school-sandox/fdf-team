/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:17:12 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 19:10:27 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (RGB(NEW_LIGHT(GET_RED(a.colour), GET_RED(b.colour), percent),
				NEW_LIGHT(GET_GREEN(a.colour), GET_GREEN(b.colour), percent),
				NEW_LIGHT(GET_BLUE(a.colour), GET_BLUE(b.colour), percent)));
}
