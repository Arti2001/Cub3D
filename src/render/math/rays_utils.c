/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 09:34:37 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 07:48:50 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	get_offset(t_root *data, double current_ray)
{
	if (current_ray > 0 && current_ray < 90)
		data->ray.x_angle = to_radiance(current_ray);
	else if (current_ray > 90 && current_ray < 180)
		data->ray.x_angle = to_radiance(180 - current_ray);
	else if (current_ray > 180 && current_ray < 270)
		data->ray.x_angle = to_radiance(current_ray - 180);
	else if (current_ray > 270 && current_ray < 360)
		data->ray.x_angle = to_radiance(360 - current_ray);
	if (current_ray > 0 && current_ray < 90)
		data->ray.y_angle = to_radiance(90 - current_ray);
	else if (current_ray > 90 && current_ray < 180)
		data->ray.y_angle = to_radiance(current_ray - 90);
	else if (current_ray > 180 && current_ray < 270)
		data->ray.y_angle = to_radiance(270 - current_ray);
	else if (current_ray > 270 && current_ray < 360)
		data->ray.y_angle = to_radiance(current_ray - 270);
	data->ray.x_offset = fabs((1 / cos(data->ray.x_angle)) * data->p.x_dist);
	data->ray.y_offset = fabs((1 / cos(data->ray.y_angle)) * data->p.y_dist);
}
/// @brief adds to the distance the correct offset
/// @param data 
/// @param current_ray 
void	add_offset(t_root *data, double current_ray)
{
	get_offset(data, current_ray);
	if (current_ray == 0 || current_ray == 180 || current_ray == 360)
		data->ray.distance = data->p.x_dist;
	else if (current_ray == 90 || current_ray == 270)
		data->ray.distance = data->p.y_dist;
	else
	{
		if(data->ray.x_offset > data->ray.y_offset)
			data->ray.distance = data->ray.y_offset;
		else
			data->ray.distance = data->ray.x_offset;
	} 
}

void	find_wall(t_root *data)
{
	double	len_x;
	double	len_y;

	data->ray.x_ray = data->p.x_pos; //also to use in the map grid
	data->ray.y_ray = data->p.y_pos;
	len_x = data->ray.x_offset * data->ray.steps_x;
	len_y = data->ray.y_offset * data->ray.steps_y;
	while (1) //add the bool wall?
	{
		if (len_x < len_y)
		{
			data->ray.distance = len_x;
			len_x += data->ray.steps_x;
			data->ray.x_ray += data->ray.dir_x;
		}
		else
		{
			data->ray.distance = len_x;
			len_x += data->ray.steps_x;
			data->ray.x_ray += data->ray.dir_x;
		}
		if (data->map.map[data->ray.y_ray][data->ray.x_ray] == '1')
		{
			// printf("I'm now [%f][%f]", data->p.y_pos, data->p.x_pos);
			// printf("I hit the wall at [%d][%d]\n",data->ray.y_ray, data->ray.x_ray);
			break ; //bool wall true ?
		}
	}
}
