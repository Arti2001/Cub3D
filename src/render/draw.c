/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/03 14:51:16 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//get the wall's height
//find where the wall should be drawn on the screen
//add the colour (and then the texture)

// static void	draw_ceiling(t_root *data, int i, int j)
// {
// 	uint32_t	ceiling;

// 	ceiling = ft_my_pixel(150, 150, 72, 255);
// 	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceiling);
// }

// static void	draw_floor(t_root *data, int i, int j)
// {
// 	uint32_t	floor;

// 	floor = ft_my_pixel(255, 211, 0, 255);
// 	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
// }

// static void	draw_wall(t_root *data, int i, int j)
// {
// 	uint32_t	floor;

// 	floor = ft_my_pixel(12, 164, 97, 255);
// 	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
// }

// void	draw_game(t_root *data, int i)
// {
// 	int	wall_height;
// 	int	wall_start;
// 	int	wall_end;
// 	int	j;

// 	// if (data->ray.flag == X)
// 	// 	data->ray.distance = fabs(data->ray.x_offset - data->ray.steps_x);
// 	// else
// 	// 	data->ray.distance = fabs(data->ray.y_offset - data->ray.steps_y);
// 	wall_height = (int)(data->cub_mlx.win_h / data->ray.distance);
// 	wall_start = -wall_height / 2 + data->cub_mlx.win_h / 2;
// 	if (wall_start < 0)
// 		wall_start = 0;
// 	wall_end = wall_height / 2 + data->cub_mlx.win_h / 2;
// 	if (wall_end >= data->cub_mlx.win_h)
// 		wall_end = data->cub_mlx.win_h - 1;
// 	j = 0;
// 	printf("distance: %f\tstart: %d\theight: %d\tend: %d\n", data->ray.distance, wall_start, wall_height, wall_end);
// 	while (j < data->cub_mlx.win_h)
// 	{
// 		// if (j < data->cub_mlx.win_h / 2 && j < wall_start && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
// 		if (j < data->cub_mlx.win_h / 2 && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))	
// 			draw_ceiling(data, i, j);
// 		// if (j > wall_start && j < wall_end && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
// 		// 		draw_wall(data, i, j);
// 		// if (j > data->cub_mlx.win_h / 2 && j > wall_end && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
// 		if (j > data->cub_mlx.win_h / 2 && ((i < data->map.mm_start_x && j < data->map.mm_start_y) || ((i > data->map.mm_start_x && j < data->map.mm_start_y) || (j > data->map.mm_start_y && i < data->map.mm_start_x))))
// 				draw_floor(data, i ,j);
// 		j++;
// 	}
// }
