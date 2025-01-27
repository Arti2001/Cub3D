/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 09:34:37 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/27 09:39:34 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	get_y_offset(t_root *data, double current_ray)
{
	if (current_ray > 0 && current_ray < 90)
	{
		data->ray->y_angle = to_radiance(90 - current_ray);
		data->p->y_offset = (1 / cos(data->ray->y_angle)) * data->p->y_dist;
	}
	else if (current_ray > 90 && current_ray < 180)
	{
		data->ray->y_angle = to_radiance(current_ray - 90);
		data->p->y_offset = (1 / cos(data->ray->y_angle)) * data->p->y_dist;
	}
	else if (current_ray > 180 && current_ray < 270)
	{
		data->ray->y_angle = to_radiance(270 - current_ray);
		data->p->y_offset = (1 / cos(data->ray->y_angle)) * data->p->y_dist;
	}
	else if (current_ray > 270 && current_ray < 360)
	{
		data->ray->y_angle = to_radiance(current_ray - 270);
		data->p->y_offset = (1 / cos(data->ray->y_angle)) * data->p->y_dist;
	}
}

static void	get_x_offset(t_root *data, double current_ray)
{
	if (current_ray > 0 && current_ray < 90)
	{
		data->ray->x_angle = to_radiance(current_ray);
		data->p->x_offset = (1 / cos(data->ray->x_angle)) * data->p->x_dist;
	}
	else if (current_ray > 90 && current_ray < 180)
	{
		data->ray->x_angle = to_radiance(180 - current_ray);
		data->p->x_offset = (1 / cos(data->ray->x_angle)) * data->p->x_dist;
	}
	else if (current_ray > 180 && current_ray < 270)
	{
		data->ray->x_angle = to_radiance(current_ray - 180);
		data->p->x_offset = (1 / cos(data->ray->x_angle)) * data->p->x_dist;
	}
	else if (current_ray > 270 && current_ray < 360)
	{
		data->ray->x_angle = to_radiance(360 - current_ray);
		data->p->x_offset = (1 / cos(data->ray->x_angle)) * data->p->x_dist;
	}
}

void	add_offset(t_root *data, double current_ray)
{
	get_x_offset(data, current_ray);
	get_y_offset(data, current_ray);
	if (current_ray == 0 || current_ray == 180 || current_ray == 360)
		data->ray->distance = data->p->x_dist;
	else if (current_ray == 90 || current_ray == 270)
		data->ray->distance = data->p->y_dist;
	else
	{
		if(data->p->x_offset > data->p->y_offset)
			data->ray->distance += data->p->y_offset;
		else
			data->ray->distance += data->p->x_offset;
	} 
}
