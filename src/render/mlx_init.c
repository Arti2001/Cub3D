/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:21:53 by amysiv        #+#    #+#                 */
/*   Updated: 2025/02/04 10:46:14 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/// @brief sets the window size & the starting point of the mini_map
static void	win_init(t_root *data)
{
	data->cub_mlx.win_h = 1280;
	data->cub_mlx.win_w = 2048;
	data->map.mm_start_x = data->cub_mlx.win_w - data->map.lenght * MMTW;
	data->map.mm_start_y = data->cub_mlx.win_h - data->map.height * MMTH;
}

static void	cub_init(t_root *data)
{
	mlx_image_t	*map;

	win_init(data);
	data->cub_mlx.win = mlx_init(data->cub_mlx.win_w, data->cub_mlx.win_h, \
		NAME, false);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	data->cub_mlx.img.img_ptr = mlx_new_image(data->cub_mlx.win, \
		data->cub_mlx.win_w, data->cub_mlx.win_h);
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
}

void	run_mlx(t_root *data)
{
	cub_init(data);
	mlx_loop_hook(data->cub_mlx.win, &key_hooks, data);
	mlx_loop_hook(data->cub_mlx.win, &draw_game, data);
	mlx_loop(data->cub_mlx.win);
	mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img.img_ptr);
	mlx_terminate(data->cub_mlx.win);
}
