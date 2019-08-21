/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:26:00 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/21 14:20:20 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define PURPLE_COLOR		0xBD93F9
# define PINK1_COLOR		0xFC5DB9
# define PINK_COLOR			0xEB6DB6
# define GREEN_COLOR		0x50FA7B
# define BLUE_COLOR		    0x8BE9FD
# define CYAN_COLOR		    0x6B75FF
# define YELLOW_COLOR		0xFFB86C
# define TEXT_COLOR			0xF2F2F2

# define HIGH_COLOR			PINK1_COLOR
# define LOW_COLOR			GREEN_COLOR

# define GET_RED(color)		((color >> 16) & 0xFF)
# define GET_GREEN(color)	((color >> 8) & 0xFF)
# define GET_BLUE(color)	(color & 0xFF)
# define RGB(r, g, b)	    ((r << 16) | (g << 8) | b)

# define NEW_LIGHT(a, b, per)	((int)((1 - per) * a + per * b))

#endif
