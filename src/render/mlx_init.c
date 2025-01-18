/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:21:53 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/18 12:03:45 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cub_init(t_root *data)
{
	mlx_image_t	*map; //created for norminette reasons (too long line 33)

	data->cub_mlx.win = mlx_init(W, H, NAME, true);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	data->cub_mlx.img.img_ptr = mlx_new_image(data->cub_mlx.win, W, H);
	if (!data->cub_mlx.img.img_ptr)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_new_image() for mini_map\n");
	}
	
	add_mini_map(data);
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
	mlx_key_hook(data->cub_mlx.win, &key_hooks, data);
	mlx_loop(data->cub_mlx.win);
	mlx_delete_image(data->cub_mlx.win, data->cub_mlx.img.img_ptr);
	mlx_terminate(data->cub_mlx.win);
}