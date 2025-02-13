/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/13 09:51:58 by mstencel      ########   odam.nl         */
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

static void	draw_mm_tile(t_root *data, int	mm_coord[2], int flag)
{
	mlx_image_t	*m_map;
	uint32_t	colour;
	int			tile_x;
	int			cpy_coord[2];

	tile_x = 0;
	m_map = data->cub_mlx.img_map.img_ptr;
	if (flag == WALL || flag == SPACE)
		colour = ft_my_pixel(0, 6, 255, 255);
	else if (flag == FLOOR)
		colour = ft_my_pixel(0, 167, 255, 255);
	cpy_coord[X] = mm_coord[X];
	cpy_coord[Y] = mm_coord[Y];
	while (tile_x < MMTW)
	{
		mlx_put_pixel(m_map, cpy_coord[X], cpy_coord[Y], colour);
		cpy_coord[X]++;
		tile_x++;
	}
}

/// @brief gets the coordinates and sends the correct flag to 
	//draw the mm_tiles
/// @param mm_coord the minimap pixels' coordinates
static void	what_to_draw(t_root *data, int mm_coord[2], int map[2])
{
	char		tile;
	mlx_image_t	*m_map;

	tile = data->map.map[map[Y]][map[X]];
	m_map = data->cub_mlx.img_map.img_ptr;
	if (map[X] >= 0 && map[X] < data->map.lenght
		&& map[Y] >= 0 && map[Y] < data->map.height)
	{
		if (tile == '1')
			draw_mm_tile(data, mm_coord, WALL);
		else if (tile == '0')
			draw_mm_tile(data, mm_coord, FLOOR);
		else if (tile == ' ')
			draw_mm_tile(data, mm_coord, SPACE);
	}
	else
		mlx_put_pixel(m_map, mm_coord[X], mm_coord[Y], 0x0);
}

	/*
		mm_coord[2];
		current coordinates on all of the minimap (0 - MM_DIMENSION)
		
		mm_start[2];
		start of the mm based on the player's position
		
		map[2];
		the real grid from the file (to check if it's 1, 0 or space)
	*/
void	add_mini_map(t_root *data)
{
	int		mm_coord[2];
	double	mm_start[2];
	int		map[2];

	mm_start[X] = data->p.x_pos - (MM_DIMENSION / MMTH / 2.0);
	mm_start[Y] = data->p.y_pos - (MM_DIMENSION / MMTH / 2.0);
	mm_coord[Y] = 0;
	while (mm_coord[Y] < MM_DIMENSION)
	{
		mm_coord[X] = 0;
		while (mm_coord[X] < MM_DIMENSION)
		{
			map[X] = (int)(mm_start[X] + (double)mm_coord[X] / MMTH);
			map[Y] = (int)(mm_start[Y] + (double)mm_coord[Y] / MMTH);
			what_to_draw(data, mm_coord, map);
			mm_coord[X]++;
		}
		mm_coord[Y]++;
	}
	draw_player(data);
}
