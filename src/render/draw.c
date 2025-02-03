/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/03 08:29:13 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//get the wall's height
//find where the wall should be drawn on the screen
//add the colour (and then the texture)

void	draw_ceiling(t_root *data, int i, int j)
{
	uint32_t	ceiling;

	ceiling = ft_my_pixel(150, 150, 0, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceiling);
}

void	draw_floor(t_root *data, int i, int j)
{
	uint32_t	floor;

	floor = ft_my_pixel(255, 211, 0, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
}

void	draw_wall(t_root *data, int i, int j)
{
	uint32_t	floor;

	floor = ft_my_pixel(12, 164, 97, 255);
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, floor);
}

void	draw_game(t_root *data, int i)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	j;

	printf("distance = %f\t", data->ray.distance);
	wall_height = (int)(data->cub_mlx.win_h / data->ray.distance + EPSILON);
	// wall_start = (data->cub_mlx.win_h / 2) - (wall_height / 2);
	wall_start = -wall_height / 2 + data->cub_mlx.win_h / 2;
	if (wall_start < 0)
		wall_start = 0;
	// wall_end = wall_start + wall_height;
	wall_end = wall_height / 2 + data->cub_mlx.win_h/ 2;
	if (wall_end >= data->cub_mlx.win_h)
		wall_end = data->cub_mlx.win_h - 1;
	printf("start: %d\theight: %d\tend: %d\tscreen h:%d\n", wall_start, -wall_height, wall_end, data->cub_mlx.win_h);
	// j = wall_start;
	// while (j < wall_end)
	// {
	// 	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, 255);
	// 	j++;
	// }
	j = 0;
	while (j < data->cub_mlx.win_h)
	{
		if (j < data->cub_mlx.win_h / 2 && j < wall_start)
			draw_ceiling(data, i, j);
		if (j > wall_start && j < wall_end)
			draw_wall(data, i, j);
		if (j > data->cub_mlx.win_h / 2 && j > wall_end)
			draw_floor(data, i ,j);
		j++;
	}
}
