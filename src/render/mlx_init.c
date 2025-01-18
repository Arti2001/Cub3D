/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:53 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/17 14:37:19 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../include/cub3d.h"


mlx_texture_t	*put_png(t_root *data, char *path)
{
	mlx_texture_t	*png;

	
	png = mlx_load_png(path);
	if (!png)
	{
		error_bye_data(data, "Failure of put_png()\n");
	}
	return (png);
	
}


void	cub_init(t_root *data)
{
	mlx_image_t	*img;
	mlx_texture_t *texture;
	uint32_t						x;
	uint32_t						y;
	int							color;

	x = 0;
	y = 0;
	data->cub_mlx.win = mlx_init(W, H, NAME, true);
	if (data->cub_mlx.win == NULL)
	{
		mlx_terminate(data->cub_mlx.win);
		error_bye_data(data, "Failure of mlx_init()\n");
	}
	img = mlx_new_image(data->cub_mlx.win, W, H);
	mlx_image_to_window(data->cub_mlx.win, img, 0, 0);
	texture = put_png(data, "src/render/textures/blackhole.png");
	while(texture->height > y)
	{
		x = 0;
		while(texture->width > x)
		{
			color = extract_rgb(texture, x, y);
			mlx_put_pixel(img, x, y, color);
			x++;
		}
			y++;
	}
	//if (img == NULL || \
	//{
	// 	mlx_terminate(data->cub_mlx.win);
	//	error_bye_data(data, "Failure of mlx_init()\n");
	//}
	mlx_loop(data->cub_mlx.win);
	mlx_delete_image(data->cub_mlx.win, img);
	mlx_terminate(data->cub_mlx.win);
}	

//void	cub_init(t_root *data)
//{
//	//mlx_image_t	*map;
//	//mlx_image_t	*stars;
//	mlx_image_t	*map;

	
//	//map = data->cub_mlx.img.img_ptr;
//	data->cub_mlx.win = mlx_init(W, H, NAME, true);
//	if (data->cub_mlx.win == NULL)
//	{
//		mlx_terminate(data->cub_mlx.win);
//		error_bye_data(data, "Failure of mlx_init()\n");
//	}
//	//mini = mlx_texture_to_image(data->cub_mlx.win, put_png(data));
//	map = mlx_new_image(data->cub_mlx.win, W, H);
//	//if (map == NULL || 
//	if(mlx_image_to_window(data->cub_mlx.win, map, 0, 0) < 0)
//	{
//		mlx_terminate(data->cub_mlx.win);
//		error_bye_data(data, "Failure of mlx_init()\n");
//	}
////	 mini = mlx_new_image(data->cub_mlx.win, MMW, MMH);
//	// if (mini == NULL || \
//	// mlx_image_to_window(data->cub_mlx.win, mini, W - MMW, H - MMH) < 0)
//	// {
//	// 	mlx_terminate(data->cub_mlx.win);
//	// 	error_bye_data(data, "Failure of mlx_init()\n");
//	// }

//	mlx_loop(data->cub_mlx.win);
//	mlx_delete_image(data->cub_mlx.win, map);
//	//mlx_delete_image(data->cub_mlx.win, mini);
//	mlx_terminate(data->cub_mlx.win);
//}	




