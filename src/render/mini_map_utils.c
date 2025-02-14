/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/14 10:38:37 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/14 11:22:40 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_player_direction(t_root *data)
{
	int			i;
	double		start[2];
	int			half;
	mlx_image_t	*m_map;

	i = 0;
	start[X] = MM_DIMENSION / 2;
	start[Y] = MM_DIMENSION / 2;
	half = (int)(MMTH + MMTH / 2);
	m_map = data->cub_mlx.img_map.img_ptr;
	while (i < half)
	{
		start[X] += data->p.x_dir * 0.3;
		start[Y] += data->p.y_dir * 0.3;
		mlx_put_pixel(m_map, (int)start[X], (int)start[Y], 0xFF0000FF);
		i++;
	}
}

void	draw_player(t_root *data)
{
	int			x;
	int			y;
	double		start[2];
	mlx_image_t	*m_map;
	uint32_t	colour;

	y = 0;
	x = 0;
	start[X] = MM_DIMENSION / 2 - MMPP / 2;
	start[Y] = MM_DIMENSION / 2 - MMPP / 2;
	m_map = data->cub_mlx.img_map.img_ptr;
	colour = 0xFF0000FF;
	while (y < MMPP)
	{
		x = 0;
		while (x < MMPP)
		{
			mlx_put_pixel(m_map, (int)start[X] + x, (int)start[Y] + y, colour);
			x++;
		}
		y++;
	}
	draw_player_direction(data);
}

void	blue_it_all(t_root *data, uint32_t col)
{
	int			x;
	int			y;
	mlx_image_t	*m_map;

	m_map = data->cub_mlx.img_map.img_ptr;
	y = 0;
	while (y < MM_DIMENSION)
	{
		x = 0;
		while (x < MM_DIMENSION)
		{
			mlx_put_pixel(m_map, x, y, col);
			x++;
		}
		y++;
	}
}
