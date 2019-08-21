/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:16:37 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/08/20 18:16:40 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera		*camera_initialize(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		print_error(ERR_CAMERA_INIT);
	camera->zoom = FT_MIN(ZOOM_WIDTH, ZOOM_HEIGHT);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divider = 1;
	camera->x_offset = 0;
	camera->y_offset = -30;
	camera->projection = ISO;
	return (camera);
}
