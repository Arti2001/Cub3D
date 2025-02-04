/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 09:22:55 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/04 10:44:30 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_player(t_root *data)
{
	int	width;
	int	height;
	int	start_x;
	int	start_y;

	height = 0;
	width = 0;
	start_x = (int)(data->map.mm_start_x + (data->p.x_pos * MMTW) - MMPP / 2);
	start_y = (int)(data->map.mm_start_y + (data->p.y_pos * MMTH) - MMPP / 2);
	while (height < MMPP)
	{
		width = 0;
		while (width < MMPP)
		{
			mlx_put_pixel(data->cub_mlx.img.img_ptr, start_x + width, \
				start_y + height, 0xFF0000FF);
			width++;
		}
		height++;
	}
}

uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_root		*data;
	mlx_image_t	*map;

	data = (t_root *)param;
	data->cub_mlx.win_w = width;
	data->cub_mlx.win_h = height;
	if (data->cub_mlx.img.img_ptr)
		mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img.img_ptr);
	data->cub_mlx.img.img_ptr = mlx_new_image(data->cub_mlx.win, width, height);
	if (!data->cub_mlx.img.img_ptr)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_new_image() for mini_map\n");
	}
	map = data->cub_mlx.img.img_ptr;
	if (mlx_image_to_window(data->cub_mlx.win, map, 0, 0) < 0)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_image_to_window()\n");
	}
	add_mini_map(data);
}
