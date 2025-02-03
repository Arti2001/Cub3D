/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:44:43 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/03 12:32:02 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
/// @brief sets the size of the x & y steps
/// @param data 
/// @param current_ray 
static void	get_steps_size(t_root *data)
{
	// if (fabs(data->ray.dir_x) < EPSILON)
	if (fabs(data->ray.dir_x) == 0)
		data->ray.dir_x = EPSILON;
	else 
		data->ray.steps_x = fabs(1 / data->ray.dir_x);
	// if (fabs(data->ray.dir_y) < EPSILON)
	if (fabs(data->ray.dir_y) == 0)
		data->ray.dir_y = EPSILON;
	else
		data->ray.steps_y = fabs(1 / data->ray.dir_y);
}

static void find_player_grid_distance(t_root *data)
{
	if (data->ray.dir_x > 0)
		data->p.x_dist = (ceil(data->p.x_pos) - data->p.x_pos);
	else
		data->p.x_dist = (data->p.x_pos - floor(data->p.x_pos));

	if (data->ray.dir_y > 0)
		data->p.y_dist = (ceil(data->p.y_pos) - data->p.y_pos);
	else
		data->p.y_dist = (data->p.y_pos - floor(data->p.y_pos));
}

static void	get_direction(t_root *data, double current_ray)
{
	data->ray.dir_x = cos(to_radiance(current_ray));  // X direction
	data->ray.dir_y = sin(to_radiance(current_ray));  // Y direction
	
}

void	get_rays(t_root *data)
{
	int		i;
	double	current_ray;
	double	left_end;
	double	right_end;

	i = 1;
	current_ray = data->p.most_l + data->p.abr *i;
	// printf("first current_ray = %f\n", current_ray);
	left_end = data->p.pos - FOV / 2;
	if (left_end >= 360)
		left_end -= 360;
	else if (left_end < 0)
		left_end += 360;
	right_end = data->p.pos + FOV / 2;
	if (right_end >= 360)
		right_end -= 360;
	else if (right_end < 0)
		right_end += 360;
	// while (i < RAYS_NUMB)
	while (i < data->cub_mlx.win_w)
	{
		current_ray = data->p.most_l + data->p.abr *i;
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
		// printf("current_ray: %f\tdata->p.pos - FOV / 2: %f\tdata->p.pos + FOV / 2: %f\n", current_ray, left_end, right_end);
		if (current_ray >= left_end && current_ray <= right_end)
			draw_ray(data);
		draw_game(data, i);
		// print_ray(data, current_ray);
		i++;
	}
	// printf("last current_ray = %f\n", current_ray);
}

void	print_ray(t_root *data, double current_ray)
{
	printf("ray: %f\t", current_ray);
	printf("x_dir: %f\t", data->ray.dir_x);
	printf("x_offset: %f & y_offset: %f\t", data->ray.x_offset, data->ray.y_offset);
	printf("distance: %f\t", data->ray.distance);
	printf("x_step: %f & y_step: %f\n", data->ray.steps_x, data->ray.steps_y);
}
