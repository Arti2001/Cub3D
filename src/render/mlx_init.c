/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:21:53 by amysiv        #+#    #+#                 */
/*   Updated: 2025/02/13 13:17:56 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	load_textures(t_root *data)
{
	data->textures[0] = mlx_load_png(data->map.no_path);
	data->textures[1] = mlx_load_png(data->map.so_path);
	data->textures[2] = mlx_load_png(data->map.ea_path);
	data->textures[3] = mlx_load_png(data->map.we_path);
	if (!data->textures[0] || !data->textures[1] || !data->textures[2]
		|| !data->textures[3])
	{
		free_mlx(data);
		free_data(data);
	}
}

static void	win_init(t_root *data)
{
	data->cub_mlx.win_h = 1280;
	data->cub_mlx.win_w = 2048;
	data->cub_mlx.win = mlx_init(data->cub_mlx.win_w, data->cub_mlx.win_h, \
		NAME, false);
	if (data->cub_mlx.win == NULL)
		error_bye_mlx_data(data, "Failure of mlx_init()\n");
}

static void	img_init(t_root *data)
{
	data->cub_mlx.img.img_ptr = mlx_new_image(data->cub_mlx.win, \
		data->cub_mlx.win_w, data->cub_mlx.win_h);
	if (data->cub_mlx.img.img_ptr == NULL)
		error_bye_mlx_data(data, "Failure of mlx_new_image() for mini_map\n");
	data->cub_mlx.img_map.img_ptr = mlx_new_image(data->cub_mlx.win, \
		MM_DIMENSION, MM_DIMENSION);
	if (data->cub_mlx.img_map.img_ptr == NULL)
		error_bye_mlx_data(data, "Failure of mlx_new_image() for mini_map\n");
}

static void	cub_init(t_root *data)
{
	win_init(data);
	img_init(data);
	mlx_image_to_window(data->cub_mlx.win, data->cub_mlx.img.img_ptr, 0, 0);
	if (data->cub_mlx.img.img_ptr == NULL)
		error_bye_mlx_data(data, "Failure of mlx_image_to_window()\n");
	mlx_image_to_window(data->cub_mlx.win, data->cub_mlx.img_map.img_ptr, 0, 0);
	if (data->cub_mlx.img_map.img_ptr == NULL)
		error_bye_mlx_data(data, "Failure of mlx_image_to_window()\n");
}

void	run_mlx(t_root *data)
{
	load_textures(data);
	cub_init(data);
	mlx_loop_hook(data->cub_mlx.win, &key_hooks, data);
	mlx_loop_hook(data->cub_mlx.win, &draw_game, data);
	mlx_loop(data->cub_mlx.win);
}
