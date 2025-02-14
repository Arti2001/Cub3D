/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/14 11:24:45 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	mm_empty_tile(t_root *data, int mm_coord[2])
{
	mlx_image_t	*m_map;
	int			cpy_coord[2];
	uint32_t	col;

	col = ft_my_pixel(0, 6, 255, 255);
	m_map = data->cub_mlx.img_map.img_ptr;
	cpy_coord[X] = mm_coord[X];
	cpy_coord[Y] = mm_coord[Y];
	while (cpy_coord[X] < MM_DIMENSION
		&& cpy_coord[Y] < MM_DIMENSION)
	{
		mlx_put_pixel(m_map, cpy_coord[X], cpy_coord[Y], col);
		cpy_coord[X]++;
	}
}

void	mm_tile(t_root *data, int mm_coord[2], int flag, uint32_t colours[2])
{
	mlx_image_t	*m_map;
	uint32_t	col;
	int			tile_x;
	int			cpy_coord[2];

	tile_x = 0;
	col = 0;
	m_map = data->cub_mlx.img_map.img_ptr;
	if (flag == WALL)
		col = colours[WALL];
	else if (flag == FLOOR)
		col = colours[FLOOR];
	cpy_coord[X] = mm_coord[X];
	cpy_coord[Y] = mm_coord[Y];
	while (tile_x < MMTW && mm_coord[X] + tile_x < MM_DIMENSION
		&& mm_coord[Y] < MM_DIMENSION)
	{
		mlx_put_pixel(m_map, cpy_coord[X], cpy_coord[Y], col);
		cpy_coord[X]++;
		tile_x++;
	}
}

/// @brief gets the coordinates and sends the correct flag to 
	//draw the mm_tiles
/// @param mm_coord the minimap pixels' coordinates
static void	what_to_draw(t_root *d, int mm_coord[2], int m[2], uint32_t col[2])
{
	char		tile;
	mlx_image_t	*m_map;
	const int	len = ft_strlen(d->map.map[m[Y]]);

	if (m[Y] >= d->map.height || m[X] >= len)
		return ;
	if (!d->map.map[m[Y]])
		return ;
	m_map = d->cub_mlx.img_map.img_ptr;
	tile = d->map.map[m[Y]][m[X]];
	if (!tile || (tile != '1' && tile != '0' && tile != ' '))
		return ;
	if (m[X] >= 0 && m[X] < d->map.lenght
		&& m[Y] >= 0 && m[Y] < d->map.height)
	{
		if (tile == '0')
			mm_tile(d, mm_coord, FLOOR, col);
		else
			mm_tile(d, mm_coord, WALL, col);
	}
}

/// @param data 
/// @param m (map) - grid coordinates
/// @param mm_c (mm_coord) - minimap coordinates/pixels - 0 - MM_DIMENSION
/// @param col (colours) - floor and wall colours
static void	start_mm_draw(t_root *data, int m[2], int mm_c[2], uint32_t col[2])
{
	if (m[Y] < 0 || m[Y] >= data->map.height
		|| m[X] < 0 || m[X] >= data->map.lenght)
		return ;
	else
		what_to_draw(data, mm_c, m, col);
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
	int			mm_coord[2];
	double		mm_start[2];
	int			map[2];
	uint32_t	colours[2];
	double		total;

	total = MM_DIMENSION / MMTH / 2.0;
	mm_start[X] = data->p.x_pos - total;
	mm_start[Y] = data->p.y_pos - total;
	colours[WALL] = ft_my_pixel(0, 6, 255, 255);
	colours[FLOOR] = ft_my_pixel(0, 167, 255, 255);
	mm_coord[Y] = 0;
	while (mm_coord[Y] < MM_DIMENSION)
	{
		mm_coord[X] = 0;
		while (mm_coord[X] < MM_DIMENSION)
		{
			map[X] = (int)(mm_start[X] + (double)mm_coord[X] / MMTH);
			map[Y] = (int)(mm_start[Y] + (double)mm_coord[Y] / MMTH);
			start_mm_draw(data, map, mm_coord, colours);
			mm_coord[X]++;
		}
		mm_coord[Y]++;
	}
	draw_player(data);
}
