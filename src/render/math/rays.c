/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 12:24:23 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/03 14:50:40 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	get_wall(t_root *data, int *ray_x, int *ray_y, int step_x, int step_y)
{
	while (1)
	{
		if (data->ray.x_offset < data->ray.y_offset)
		{
			data->ray.x_offset += data->ray.steps_x;
			*ray_x += step_x;
			data->ray.flag = X;
		}
		else
		{
			data->ray.y_offset += data->ray.steps_y;
			*ray_y += step_y;
			data->ray.flag = Y;
		}
		if (data->ray.x_ray < 0 || data->ray.x_ray >= data->map.height || 
			data->ray.y_ray < 0 || data->ray.y_ray >= data->map.lenght)
			break;
		if (data->map.map[(int)data->ray.y_ray][(int)data->ray.x_ray] == '1')
			break ;
	}
}

static void	get_offset(t_root *data, int *ray_x, int *ray_y)
{
	int	step_x; //either +1 or -1
	int	step_y; //either +1 or -1
	if (data->ray.dir_x < 0)
	{
		step_x = -1;
		data->ray.x_offset = (data->p.x_pos - *ray_x) * data->ray.steps_x;
	}
	else
	{
		step_x = 1;
		data->ray.x_offset = (*ray_x + 1.0 - data->p.x_pos) * data->ray.steps_x;
	}
	if (data->ray.dir_y < 0)
	{
		step_y = -1;
		data->ray.y_offset = (data->p.y_pos - *ray_y) * data->ray.steps_y;
	}
	else
	{
		step_y = 1;
		data->ray.y_offset = (*ray_y + 1.0 - data->p.y_pos) * data->ray.steps_y;
	}
	get_wall(data, ray_x, ray_y, step_x, step_y);
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

static void	get_direction(t_root *data, int dir_x, int dir_y, int plane_x, int plane_y)
{	
	data->ray.dir_x = dir_x + plane_x * data->ray.camera_x;
	data->ray.dir_y = dir_y + plane_y * data->ray.camera_x;
}

static void	get_distance(t_root *data)
{
	if (data->ray.flag == X)
		data->ray.distance = data->ray.x_offset - data->ray.steps_x;
	else
	data->ray.distance = data->ray.y_offset - data->ray.steps_y;
}

void	draw_ceiling(t_root *data, int i, int j)
{
	uint32_t	ceiling;

	ceiling = ft_my_pixel(150, 150, 72, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceiling);
}

void	draw_floor(t_root *data, int i, int j)
{
	uint32_t	floor;

	floor = ft_my_pixel(255, 211, 0, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
}

void	draw_wall(t_root *data, int i, int j)
{
	uint32_t	floor;

	floor = ft_my_pixel(12, 164, 97, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
}

static void	draw_walls(t_root *data, int i)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	j;

	wall_height = (int)(data->cub_mlx.win_h / data->ray.distance);
	wall_start = - wall_height / 2 + data->cub_mlx.win_h / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = wall_height / 2 + data->cub_mlx.win_h / 2;
	if (wall_end >= data->cub_mlx.win_h)
		wall_end = data->cub_mlx.win_h - 1;
	j = 0;
	while (j < data->cub_mlx.win_h)
	{
		if (j < data->cub_mlx.win_h / 2 && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))	
			draw_ceiling(data, i, j);
		if (j > wall_start && j < wall_end && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
			draw_wall(data, i, j);
		if (j > data->cub_mlx.win_h / 2 && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
			draw_floor(data, i ,j);
		j++;
	}
}

void	get_rays(t_root *data)
{
	int		i;
	int		in_dir_x = -1; //initial direction vector
	int		in_dir_y = 0; //initial direction vector
	double	plane_x = 0;
	double	plane_y = 0.66;
	int	ray_x; //starting position of ray_x (player's x position)
	int	ray_y; //starting position of ray_y (player's y position)

	i = 0;
	while (i < data->cub_mlx.win_w)
	{
		ray_x = (int)data->p.x_pos;
		ray_y = (int)data->p.y_pos;
		data->ray.camera_x = 2 * i / data->cub_mlx.win_w - 1;
		get_direction(data, in_dir_x, in_dir_y, plane_x, plane_y);
		get_step_size(data);
		get_offset(data, &ray_x, &ray_y);
		get_distance(data);
		draw_walls(data, i);
		draw_ray(data);
		i++;
	}
}