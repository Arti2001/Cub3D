/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/17 15:01:22 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//open an image that will be the size of the map (data->map->height & lenght) * mm_tiles
//add the colours of the corresponding tiles
//add the player
//add the direction where it's facing
//add the rays

void	get_mini_map(t_root *data)
{
	int		x;
	int		y;
	long	width;
	long	height;

	
	width = data->map->lenght * MMTW;
	height = data->map->height * MMTH;
	y = H - height;
	while (y < H && y > 0)
	{
		x = W - width;
		while(x < W && x > 0)
		{
			mlx_put_pixel(data->cub_mlx.img.img_ptr, x, y, 255);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(data->cub_mlx.win, data->cub_mlx.img.img_ptr, 0, 0) < 0)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_image_to_window()\n");
	}
}
