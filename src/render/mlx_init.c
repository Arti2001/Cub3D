/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:21:53 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/27 08:24:25 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	win_init(t_root *data)
{
	data->cub_mlx.win_h = 1280;
	data->cub_mlx.win_w = 2048;
}

static void	cub_init(t_root *data)
{
	mlx_image_t	*map; //created for norminette reasons (too long line 33)

	win_init(data);
	data->cub_mlx.win = mlx_init(data->cub_mlx.win_w, data->cub_mlx.win_h, NAME, true);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	data->cub_mlx.img.img_ptr = mlx_new_image(data->cub_mlx.win, data->cub_mlx.win_w, data->cub_mlx.win_h);
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
	mlx_resize_hook(data->cub_mlx.win, ft_resize, data);
	add_mini_map(data);
}

void	run_mlx(t_root *data)
{
	handel_angel(data);
	get_rays(data);
	cub_init(data);
	mlx_key_hook(data->cub_mlx.win, &key_hooks, data);
	mlx_loop(data->cub_mlx.win);
	mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img.img_ptr);
	mlx_terminate(data->cub_mlx.win);
}