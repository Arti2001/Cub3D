/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:14:41 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/06 09:59:02 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


uint32_t	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
void	load_textures(t_root *data)
{
	
	data->textures[0] = mlx_load_png(data->map.no_path);
	data->textures[1] = mlx_load_png(data->map.so_path);
	data->textures[2] = mlx_load_png(data->map.ea_path);
	data->textures[3] = mlx_load_png(data->map.we_path);
	if (!data->textures[0] || \
		!data->textures[1] || \
		!data->textures[2] || \
		!data->textures[3])
	error_bye_data(data, ERR_NO_PATH_FOUND);
}

void	draw_wall(t_root *data, int i, int j)
{
	//extract_rgb(data->textures[0], 0, 0);
	
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, get_rgb(50, 14, 43, 255));
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
	add_mini_map(data);
}
