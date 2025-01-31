/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/30 11:42:23 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//get the wall's height
//find where the wall should be drawn on the screen
//add the colour (and then the texture)

void	draw_wall(t_root *data, int i)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	j;

	// printf("distance = %f", data->ray.distance);
	wall_height = (int)(data->cub_mlx.win_h / data->ray.distance + EPSILON);
	wall_start = (data->cub_mlx.win_h / 2) - (wall_height / 2);
	if (wall_start < 0)
		wall_start = 0;
	wall_end = wall_start + wall_height;
	if (wall_end > data->cub_mlx.win_h)
		wall_end = data->cub_mlx.win_h;
	j = wall_start;
	while (j < wall_end)
	{
		mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, 0xFF0000);
		j++;
	}
}
