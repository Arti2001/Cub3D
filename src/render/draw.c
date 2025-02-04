/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/04 10:38:29 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_root *data, int i, int j)
{
	uint32_t	wall;

	wall = ft_my_pixel(12, 164, 97, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, wall);
}

static bool	mm_check(t_root *data, int i, int j)
{
	if ((i <= data->map.mm_start_x && j <= data->map.mm_start_y) \
		|| ((i > data->map.mm_start_x && j < data->map.mm_start_y) \
		|| (j > data->map.mm_start_y && i < data->map.mm_start_x)))
		return (true);
	return (false);
}

static void	draw_walls(t_root *data, int i, uint32_t ceiling, uint32_t floor)
{
	t_wall		wall;
	int			j;

	wall.height = (int)(data->cub_mlx.win_h / data->ray.distance);
	wall.start = (int)((data->cub_mlx.win_h - wall.height) / 2);
	wall.end = (int)(wall.height + data->cub_mlx.win_h) / 2;
	j = 0;
	while (j < data->cub_mlx.win_h)
	{
		if (j < wall.start && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceiling);
		if (j >= wall.start && j <= wall.end && mm_check(data, i, j) == true)
			draw_wall(data, i, j);
		if (j > wall.end && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
		j++;
	}
}

// get_rays(data, i) is doing doing all the math 
// (getting the distance between the wall & the player)
void	draw_game(void *param)
{
	t_root		*data;
	int			i;
	uint32_t	ceiling;
	uint32_t	floor;

	data = param;
	i = 0;
	ceiling = ft_my_pixel(data->map.ceiling.r, data->map.ceiling.g, \
		data->map.ceiling.b, 255);
	floor = ft_my_pixel(data->map.floor.r, data->map.floor.g, \
		data->map.floor.b, 255);
	while (i < data->cub_mlx.win_w)
	{
		get_rays(data, i);
		draw_walls(data, i, ceiling, floor);
		i++;
	}
	draw_ray(data);
	add_mini_map(data);
}
