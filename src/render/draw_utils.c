/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 09:34:37 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/06 09:05:00 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	draw_ray(t_root *data)
{
	double		ray_x;
	double		ray_y;
	uint32_t	x;
	uint32_t	y;
	
	ray_x = data->p.x_pos;
	ray_y = data->p.y_pos;
	while (ray_x >= 0 && ray_y >= 0 && ray_x < data->map.lenght  && ray_y < data->map.height)
	{
		x = (uint32_t)(data->map.mm_start_x + ray_x * MMTW);
		y = (uint32_t)(data->map.mm_start_y + ray_y * MMTH);
		mlx_put_pixel(data->cub_mlx.img.img_ptr, x, y, 255);
		ray_x += data->p.x_dir * 0.1;
		ray_y += data->p.y_dir * 0.1;
		if (data->map.map[(int)ray_y][(int)ray_x] == '1')
			break ;
	}
}
