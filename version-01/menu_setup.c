/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:11:59 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 19:20:46 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	controls_menu(t_fdf *fdf)
{
	S(15, 20, YELLOW_COLOR, "CONTROLS");
	S(15, 55, TEXT_COLOR, "Move:");
	S(85, 55, PINK_COLOR, "Arrows");
	S(155, 55, TEXT_COLOR, "|");
	S(175, 45, PINK_COLOR, "  W");
	S(175, 65, PINK_COLOR, "A S D");
	S(15, 95, TEXT_COLOR, "Zoom:");
	S(85, 95, PINK_COLOR, "Scroll");
	S(155, 92, TEXT_COLOR, "|");
	S(175, 95, PINK_COLOR, "+/-");
	S(15, 135, TEXT_COLOR, "Scale Z:");
	S(135, 135, PINK_COLOR, "<");
	S(155, 132, TEXT_COLOR, "|");
	S(175, 135, PINK_COLOR, ">");
	S(15, 210, TEXT_COLOR, "Rotate:");
	S(105, 170, PINK_COLOR, " U/J   I/K   O/L ");
	S(105, 190, TEXT_COLOR, " +   +   + ");
	S(105, 210, PINK_COLOR, "[X] [Y] [Z]");
}

static void	projection_menu(t_fdf *fdf)
{
	S(15, 325, YELLOW_COLOR, "PROJECTION");
	S(15, 360, TEXT_COLOR, "Horizontal:");
	S(155, 360, PINK_COLOR, "1");
	S(15, 390, TEXT_COLOR, "FRONT:");
	S(155, 390, PINK_COLOR, "2");
	S(15, 420, TEXT_COLOR, "CROSS:");
	S(155, 420, PINK_COLOR, "3");
	S(15, 450, TEXT_COLOR, "ISO:");
	S(155, 450, PINK_COLOR, "4");
}

void		setup_menu(t_fdf *fdf)
{
	controls_menu(fdf);
	projection_menu(fdf);
}
