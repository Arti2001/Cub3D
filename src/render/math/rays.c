/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:44:43 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 09:32:59 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

/// @brief sets the size of the x & y steps
/// @param data 
/// @param current_ray 
static void	get_steps_size(t_root *data)
{
	data->ray.steps_x = 1 / cos(data->ray.x_angle);
	data->ray.steps_y = 1 / cos(data->ray.y_angle);
}

/// @brief sets the dist_x and dist_y depending on how far the player is
//	from the nearest line
/// @param data 
static void	find_player_grid_distance(t_root *data)
{
	if (data->ray.dir_x == 1)
		data->p.x_dist = (ceil(data->p.x_pos) - data->p.x_pos);
	else if (data->ray.dir_x == -1)
		data->p.x_dist = (data->p.x_pos - floor(data->p.x_pos));
	else
		data->p.x_dist = 0;
	if (data->ray.dir_y == 1)
		data->p.y_dist = (ceil(data->p.y_pos) - data->p.y_pos);
	else if (data->ray.dir_y == -1)
		data->p.y_dist = (data->p.y_pos - floor(data->p.y_pos));
	else
		data->p.y_dist = 0;
}

/// @brief sets directions for 0, 90, 180, 270 & 360 degrees
/// @param data 
/// @param current_ray 
static void	get_round_directions(t_root *data, double current_ray)
{
	if (current_ray == 0 || current_ray == 360)
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
	}
	else if (current_ray == 90)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
	}
	else if (current_ray == 180)
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
	}
	else if (current_ray == 270)
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
	}
}
/// @brief if the ray goes right, it's dir_x= 1, if left dir_x = -1; 
//	if it goes down it's dir_y = 1, if up dir_y = -1,
static void	get_direction(t_root *data, double current_ray)
{
	if (current_ray > 0 && current_ray < 90)
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 1;
	}
	else if (current_ray > 90 && current_ray < 180)
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 1;
	}
	else if (current_ray > 180 && current_ray < 270)
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = -1;
	}
	else if (current_ray > 270 && current_ray < 360)
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = -1;
	}
	else if (current_ray == 0 || current_ray == 90 || current_ray == 180 
		|| current_ray == 270 || current_ray == 360)
		get_round_directions(data, current_ray);
}

void	get_rays(t_root *data)
{
	int		i;
	double	current_ray;

	i = 1;
	while (i < RAYS_NUMB)
	// while (i < data->cub_mlx.win_w)
	{
		current_ray = data->p.most_l + data->p.abr * i;
		if (current_ray >= 360)
			current_ray -= 360;
		else if (current_ray < 0)
			current_ray += 360;
		// printf("current_ray: %f\n", current_ray);
		get_direction(data, current_ray);
		find_player_grid_distance(data);
		add_offset(data, current_ray);
		get_steps_size(data);
		find_wall(data);
		draw_ray(data);
		// print_ray(data, current_ray);
		i++;
	}
}

void	print_ray(t_root *data, double current_ray)
{
	printf("ray: %f\t", current_ray);
	printf("x_dir: %d\t", data->ray.dir_x);
	printf("x_offset: %f & y_offset: %f\t", data->ray.x_offset, data->ray.y_offset);
	printf("distance: %f\t", data->ray.distance);
	printf("x_step: %f & y_step: %f\n", data->ray.steps_x, data->ray.steps_y);
}
