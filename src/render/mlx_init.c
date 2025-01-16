/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:53 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/16 13:54:15 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../include/cub3d.h"


mlx_texture_t	*put_png(t_root *data)
{
	mlx_texture_t	*png;

	png = mlx_load_png("src/render/blackhole.png");
	if (!png)
	{
		error_bye_data(data, "Failure of put_png()\n");
	}
	return (png);
	
}

void	cub_init(t_root *data)
{
	//mlx_image_t	*map;
	mlx_image_t	*stars;
	 mlx_image_t	*mini;

	
	//map = data->cub_mlx.img.img_ptr;
	data->cub_mlx.win = mlx_init(W, H, NAME, true);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	stars = mlx_texture_to_image(data->cub_mlx.win, put_png(data));
	mini = mlx_texture_to_image(data->cub_mlx.win, put_png(data));
	//map = mlx_new_image(data->cub_mlx.win, W, H);
	//if (map == NULL || 
	if(mlx_image_to_window(data->cub_mlx.win, stars, 0, 0) < 0)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
//	 mini = mlx_new_image(data->cub_mlx.win, MMW, MMH);
	 if (mini == NULL || \
	 mlx_image_to_window(data->cub_mlx.win, mini, W - MMW, H - MMH) < 0)
	 {
	 	mlx_terminate(data->cub_mlx.win);
	 	error_bye_data(data, "Failure of mlx_init()\n");
	 }

	mlx_loop(data->cub_mlx.win);
	mlx_delete_image(data->cub_mlx.win, stars);
	mlx_delete_image(data->cub_mlx.win, mini);
	mlx_terminate(data->cub_mlx.win);
}	




