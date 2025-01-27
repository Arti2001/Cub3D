/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:44:43 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/27 09:35:42 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	find_distance(t_root *data)
{
	if (data->ray->dir_x == 1)
		data->p->x_dist = (ceil(data->p->x_pos) - data->p->x_pos) * TW;
	else if (data->ray->dir_x == -1)
		data->p->x_dist = (data->p->x_pos - floor(data->p->x_pos)) * TW;
	else
		data->p->x_dist = 0;
	if (data->ray->dir_y == 1)
		data->p->y_dist = (ceil(data->p->y_pos) - data->p->y_pos) * TH;
	else if (data->ray->dir_y == -1)
		data->p->y_dist = (data->p->y_pos - floor(data->p->y_pos)) * TH;
	else
		data->p->y_dist = 0;
}

static void	get_round_directions(t_root *data, double current_ray)
{
	if (current_ray == 0 || current_ray == 360)
	{
		data->ray->dir_x = 1;
		data->ray->dir_y = 0;
	}
	else if (current_ray == 90)
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = 1;
	}
	else if (current_ray == 180)
	{
		data->ray->dir_x = -1;
		data->ray->dir_y = 0;
	}
	else if (current_ray == 270)
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = -1;
	}
}

static void	get_direction(t_root *data, double current_ray)
{
	if (current_ray > 0 && current_ray < 90)
	{
		data->ray->dir_x = 1;
		data->ray->dir_y = 1;
	}
	else if (current_ray > 90 && current_ray < 180)
	{
		data->ray->dir_x = -1;
		data->ray->dir_y = 1;
	}
	else if (current_ray > 180 && current_ray < 270)
	{
		data->ray->dir_x = -1;
		data->ray->dir_y = -1;
	}
	else if (current_ray > 270 && current_ray < 360)
	{
		data->ray->dir_x = 1;
		data->ray->dir_y = -1;
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
	while (i <= RAYS_NUMB)
	{
		current_ray = data->p->most_l + data->p->abr * i;
		get_direction(data, current_ray);
		find_distance(data);
		add_offset(data, current_ray);
		i++;
	}
	
}
