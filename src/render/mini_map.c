/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:07:46 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/10 11:03:21 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/// @brief makes sure that map will always be black if the line is shorter than
	//the width of the map
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place 
static void	draw_rest(t_root *data, int img[2])
{
	int	i;

	i = 0;
	while (i < MMTW && img[X] < MM_DIMENTION)
	{
		mlx_put_pixel(data->cub_mlx.img_map.img_ptr, img[X], img[Y], 255);
		img[X]++;
		i++;
	}
}

/// @brief puts the adequate pixels (depending on the flag) in the image
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place 
/// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour 
static void	draw_map2(t_root *data, int img[2], int flag)
{
	uint32_t	colour[5];
	mlx_image_t	*map;

	map = data->cub_mlx.img_map.img_ptr;
	colour[WALL] = ft_my_pixel(0, 6, 255, 255);
	colour[FLOOR] = ft_my_pixel(0, 167, 255, 255);
	colour[SPACE] = ft_my_pixel(0, 0, 0, 255);
	if (flag == WALL)
		mlx_put_pixel(map, img[X], img[Y], colour[WALL]);
	else if (flag == FLOOR)
		mlx_put_pixel(map, img[X], img[Y], colour[FLOOR]);
	else
		mlx_put_pixel(map, img[X], img[Y], colour[SPACE]);
}

/// @brief will draw only the black (space or the tiles' outlines)
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place
/// @param j current height in the tile in the minimap
/// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour
static void	draw_map1(t_root *data, int mm_coord[2], int flag, int tile_y)
{
	int		i;

	i = 0;
	while (i < MMTW && mm_coord[X] < MM_DIMENTION)
	{
		if (tile_y == 0 || i == 0)
			mlx_put_pixel(data->cub_mlx.img_map.img_ptr, mm_coord[X], \
				mm_coord[Y], 255);
		else
			draw_map2(data, mm_coord, flag);
		mm_coord[X]++;
		i++;
	}
}

/// @brief checks that the width of the minimap is correct, goes to another
	//function checking whats on the map (1 0 N S W E ' ')
/// @param data needed for the map img pointer
/// @param y current height of the real map
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place
/// @param j current height in the tile in the minimap
//static void	draw_map(t_root *data, int y, int mm_coord[2], int tile_y)
//{
//	int	x;

//	x = 0;
//	mm_coord[X] = 0;
//	while (data->map.map[y][x] && mm_coord[X] < MM_DIMENTION)
//	{
//		draw_player(data);
//		if (data->map.map[y][x] == '1')
//			draw_map1(data, mm_coord, WALL, tile_y);
//		else if (data->map.map[y][x] == '0')
//			draw_map1(data, mm_coord, FLOOR, tile_y);
//		else if (data->map.map[y][x] == ' ')
//			draw_map1(data, mm_coord, SPACE, tile_y);
//		x++;
//	}
//	while (x < data->map.lenght && mm_coord[X] < MM_DIMENTION)
//	{
//		draw_rest(data, mm_coord);
//		x++;
//	}
//}

/// @brief based on the size of minimap tiles, it checks that mini map is
	// drawn withing the correct height of the map (taking into account the
	// size of mini map tiles)
//void	add_mini_map(t_root *data)
//{
//	int	y;
//	int	mm_coord[2];
//	int	tile_y;

//	mm_coord[Y] = data->p.y_pos * MMTH - MMPP / 2;
//	y = 0;
//	while (y < data->map.height && mm_coord[Y] < MM_DIMENTION)
//	{
//		tile_y = 0;
//		while (tile_y < MMTH && mm_coord[Y] < MM_DIMENTION)
//		{
//			draw_map(data, y, mm_coord, tile_y);
//			mm_coord[Y]++;
//			tile_y++;
//		}
//		y++;
//	}
//	draw_ray(data);
//}

void add_mini_map(t_root *data)
{
	int y, x;
	int mm_coord[2];  // Minimap pixel coordinates
	int tile_y;

	// Calculate the top-left corner of the minimap
	int start_y = (int)data->p.y_pos - (MM_DIMENTION / MMTH) / 2;
	int start_x = (int)data->p.x_pos - (MM_DIMENTION / MMTW) / 2;

	mm_coord[Y] = 0;
	y = start_y;

	while (y < data->map.height && mm_coord[Y] < MM_DIMENTION)
	{
		tile_y = 0;
		while (tile_y < MMTH && mm_coord[Y] < MM_DIMENTION)
		{
			mm_coord[X] = 0;
			x = start_x;

			while (x < data->map.lenght && mm_coord[X] < MM_DIMENTION)
			{
				if (x >= 0 && y >= 0 && x < data->map.lenght && y < data->map.height)
				{
					if (data->map.map[y][x] == '1')
						draw_map1(data, mm_coord, WALL, tile_y);
					else if (data->map.map[y][x] == '0')
						draw_map1(data, mm_coord, FLOOR, tile_y);
					else if (data->map.map[y][x] == ' ')
						draw_map1(data, mm_coord, SPACE, tile_y);
				}
				else
					draw_rest(data, mm_coord); // Draw black if out of bounds

				mm_coord[X]++;
				x++;
			}
			mm_coord[Y]++;
			tile_y++;
		}
		y++;
	}

	draw_player(data);  // Player is always centered
	draw_ray(data);
}