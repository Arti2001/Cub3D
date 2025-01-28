/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 09:34:37 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 09:47:27 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	draw_ray(t_root *data)
{
	double		ray_x;
	double		ray_y;
	uint32_t	x;
	uint32_t	y;
	
	ray_x = data->p.x_pos;
	ray_y = data->p.y_pos;
	while (ray_x >= 0 && ray_y >= 0 && ray_x < data->map.lenght && ray_y < data->map.height)
	{
		x = (uint32_t)(data->map.mm_start_x + ray_x * MMTW);
		y = (uint32_t)(data->map.mm_start_y + ray_y * MMTH);
		mlx_put_pixel(data->cub_mlx.img.img_ptr, x, y, 0xFFFF00FF);
		ray_x += data->ray.dir_x * 0.05;
		ray_y += data->ray.dir_y * 0.05;
		if (data->map.map[(int)ray_y][(int)ray_x] == '1')
			break ;
	}
}

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
