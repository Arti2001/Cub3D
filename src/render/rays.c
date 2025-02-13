/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 12:24:23 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/13 10:25:18 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	get_wall(t_root *data, int step_x, int step_y)
{
	while (1)
	{
		if (data->ray.x_off < data->ray.y_off)
		{
			data->ray.x_off += data->ray.steps_x;
			data->ray.x_map += step_x;
			if (data->ray.dir_x < 0)
				data->ray.side = WEST;
			else
				data->ray.side = EAST;
		}
		else
		{
			data->ray.y_off += data->ray.steps_y;
			data->ray.y_map += step_y;
			if (data->ray.dir_y < 0)
				data->ray.side = NORTH;
			else
				data->ray.side = SOUTH;
		}
		if (data->ray.x_map < 0 || data->ray.x_map >= data->map.lenght
			|| data->ray.y_map < 0 || data->ray.y_map >= data->map.height
			|| data->map.map[data->ray.y_map][data->ray.x_map] == '1')
			break ;
	}
}

static int	get_offset_y(t_root *data)
{
	int	step_y;

	if (data->ray.dir_y < 0)
	{
		step_y = -1;
		data->ray.y_off = (data->p.y_pos - data->ray.y_map) * data->ray.steps_y;
	}
	else
	{
		step_y = 1;
		data->ray.y_off = (data->ray.y_map + 1.0 - data->p.y_pos) \
			* data->ray.steps_y;
	}
	return (step_y);
}

static void	get_offset(t_root *data)
{
	int	step_x;
	int	step_y;

	if (data->ray.dir_x < 0)
	{
		step_x = -1;
		data->ray.x_off = (data->p.x_pos - data->ray.x_map) * data->ray.steps_x;
	}
	else
	{
		step_x = 1;
		data->ray.x_off = (data->ray.x_map + 1.0 - data->p.x_pos) \
			* data->ray.steps_x;
	}
	step_y = get_offset_y(data);
	get_wall(data, step_x, step_y);
}

static void	get_step_size(t_root *data)
{
	if (data->ray.dir_x == 0)
		data->ray.steps_x = EPSILON;
	else
		data->ray.steps_x = fabs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.steps_y = EPSILON;
	else
		data->ray.steps_y = fabs(1 / data->ray.dir_y);
}

void	get_rays(t_root *data, int i)
{
	data->ray.x_map = (int)data->p.x_pos;
	data->ray.y_map = (int)data->p.y_pos;
	data->ray.camera_x = 2 * i / (double)data->cub_mlx.win_w - 1;
	data->ray.dir_x = data->p.x_dir + data->p.plane_x * data->ray.camera_x;
	data->ray.dir_y = data->p.y_dir + data->p.plane_y * data->ray.camera_x;
	get_step_size(data);
	get_offset(data);
	if (data->ray.side == EAST || data->ray.side == WEST)
		data->ray.distance = data->ray.x_off - data->ray.steps_x;
	else
		data->ray.distance = data->ray.y_off - data->ray.steps_y;
}
