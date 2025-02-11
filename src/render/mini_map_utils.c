/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 09:22:55 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 07:57:18 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_player_direction(t_root *data)
{
	int		i;
	double	start_x;
	double	start_y;

	i = 0;
	start_x = (MM_DIMENTION - MMPP) / 2 + MMPP / 2;
	start_y = (MM_DIMENTION - MMPP) / 2 + MMPP / 2;
	while (i < 20)
	{
		start_x += data->p.x_dir * 0.3;
		start_y += data->p.y_dir * 0.3;
		mlx_put_pixel(data->cub_mlx.img_map.img_ptr, (int)start_x, (int)start_y, 0xFF0000FF);
		i++;
	}
}

void	draw_player(t_root *data)
{
	int		x;
	int		y;
	double	start_x;
	double	start_y;

	y = 0;
	x = 0;
	start_x = (MM_DIMENTION - MMPP) / 2;
	start_y = (MM_DIMENTION - MMPP) / 2;
	while (y < MMPP)
	{
		x = 0;
		while (x < MMPP)
		{
			mlx_put_pixel(data->cub_mlx.img_map.img_ptr, (int)start_x + x, \
				(int)start_y + y, 0xFF0000FF);
			x++;
		}
		y++;
	}
	draw_player_direction(data);
}

uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
