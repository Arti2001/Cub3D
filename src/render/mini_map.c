/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 13:19:23 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
static void	draw_map2(t_root *data, int img[2], int flag)
{
	mlx_image_t	*map = data->cub_mlx.img_map.img_ptr;
	uint32_t	color;

	// Assign color based on flag
	if (flag == WALL)
		color = ft_my_pixel(0, 6, 255, 255);
	else if (flag == FLOOR)
		color = ft_my_pixel(0, 167, 255, 255);
	else
		color = 0x0; // Default to SPACE color (black)

	// Ensure pixel is within bounds before drawing
	if (img[X] >= 0 && img[X] < MM_DIMENTION && img[Y] >= 0 && img[Y] < MM_DIMENTION)
		mlx_put_pixel(map, img[X], img[Y], color);
}

static void	draw_map1(t_root *data, int mm_coord[2], int flag)
{
	int i;

	i = 0;
	while (i < MMTW && mm_coord[X] < MM_DIMENTION)
	{
		draw_map2(data, mm_coord, flag);
		mm_coord[X]++;
		i++;
	}
}

void	add_mini_map(t_root *data)
{
	int y, x;
	int mm_coord[2];
	int map_x, map_y;
	double mm_start[2];

	// Define minimap starting position based on player
	mm_start[X] = data->p.x_pos - (MM_DIMENTION / MMTH / 2.0);
	mm_start[Y] = data->p.y_pos - (MM_DIMENTION / MMTH / 2.0);

	y = 0;
	while (y < MM_DIMENTION)
	{
		x = 0;
		while (x < MM_DIMENTION)
		{
			// Convert minimap pixel position to actual map coordinates
			map_x = (int)(mm_start[X] + (double)x / MMTH);
			map_y = (int)(mm_start[Y] + (double)y / MMTH);

			mm_coord[X] = x;
			mm_coord[Y] = y;

			if (map_x >= 0 && map_x < data->map.lenght && map_y >= 0 && map_y < data->map.height)
			{
				char tile = data->map.map[map_y][map_x];
				if (tile == '1')
					draw_map1(data, mm_coord, WALL);
				else if (tile == '0')
					draw_map1(data, mm_coord, FLOOR);
				else if (tile == ' ')
					draw_map1(data, mm_coord, SPACE);
			}
			else
				mlx_put_pixel(data->cub_mlx.img_map.img_ptr, x, y, 0x0);
			x++;
		}
		y++;
	}

	draw_player(data);
}

