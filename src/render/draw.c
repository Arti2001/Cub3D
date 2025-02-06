/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/06 08:56:13 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_wall(t_root *data, t_wall wall)
{
	int	side;
	
	if (data->ray.flag == 'X')
	{
		if (data->ray.dir_x < 0)
			side = EAST;
		else
			side = WEST;
	}
	else
	{
		if (data->ray.dir_y < 0)
			side = NORTH;
		else
			side = SOUTH;
	}
	wall.tex_x = (int)(wall.hit_point * (double)data->texture[side]->width);
	wall.step = 1.0 * data->texture[side]->height / wall.height;
	wall.tex_pos = (wall.start - data->cub_mlx.win_h / 2 + wall.height / 2) * wall.step;
	
	// uint32_t	wall;

	// wall = ft_my_pixel(12, 164, 97, 255);
	// mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, wall);
}

static bool	mm_check(t_root *data, int i, int j)
{
	if ((i <= data->map.mm_start_x && j <= data->map.mm_start_y) \
		|| ((i > data->map.mm_start_x && j < data->map.mm_start_y) \
		|| (j > data->map.mm_start_y && i < data->map.mm_start_x)))
		return (true);
	return (false);
}

static void	draw_screen(t_root *data, int i, uint32_t ceil, uint32_t fl)
{
	t_wall		wall;
	int			j;

	wall.height = (int)(data->cub_mlx.win_h / data->ray.distance);
	wall.start = (int)((data->cub_mlx.win_h - wall.height) / 2);
	wall.end = (int)(wall.height + data->cub_mlx.win_h) / 2;
	wall.map_tile = data->map.map[data->ray.x_map][data->ray.y_map] - 1;
	if (data->ray.flag == X) //for EW
		wall.hit_point = data->p.y_pos + data->ray.distance * data->ray.dir_y;
	else //for NS
		wall.hit_point = data->p.x_pos + data->ray.distance * data->ray.dir_x;
	wall.hit_point -= floor(wall.hit_point);
	j = 0;
	draw_wall(data, wall);
	while (j < data->cub_mlx.win_h)
	{
		if (j < wall.start && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceil);
		if (j >= wall.start && j <= wall.end && mm_check(data, i, j) == true)
			//resize the texture;
		if (j > wall.end && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, fl);
		j++;
	}
}

// get_rays(data, i) is doing doing all the math 
// (getting the distance between the wall & the player)
void	draw_game(void *param)
{
	t_root		*data;
	int			i;
	uint32_t	ceil;
	uint32_t	fl;

	data = param;
	i = 0;
	ceil = ft_my_pixel(data->map.ceiling.r, data->map.ceiling.g, \
		data->map.ceiling.b, 255);
	fl = ft_my_pixel(data->map.floor.r, data->map.floor.g, \
		data->map.floor.b, 255);
	while (i < data->cub_mlx.win_w)
	{
		get_rays(data, i);
		draw_screen(data, i, ceil, fl);
		i++;
	}
	add_mini_map(data);
}
