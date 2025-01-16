/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:53 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/16 11:40:28 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../include/cub3d.h"

void	cub_init(t_root *data)
{
	mlx_image_t	*map;
	//mlx_image_t	*mini;

	map = data->cub_mlx.img.img_ptr;
	//mini = data->cub_mlx.mini_map.img_ptr;
	data->cub_mlx.win = mlx_init(W, H, NAME, true);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	map = mlx_new_image(data->cub_mlx.win, W, H);
	if (map == NULL || \
	mlx_image_to_window(data->cub_mlx.win, map, 0, 0) < 0)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
//	mini = mlx_new_image(data->cub_mlx.win, MMW, MMH);
//	if (mini == NULL || \
//	mlx_image_to_window(data->cub_mlx.win, mini, W - MMW, H - MMH) < 0)
//	{
//		mlx_terminate(data->cub_mlx.win);
//		error_bye_data(data, "Failure of mlx_init()\n");
//	}
}	
