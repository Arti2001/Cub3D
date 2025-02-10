/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:07:46 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/10 14:10:47 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/// @brief makes sure that map will always be black if the line is shorter than
	//the width of the map
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place 
// static void	draw_rest(t_root *data, int x, int y)
// {
// 	int	i;

// 	i = 0;
// 	while (i < MMTW && img[X] < MM_DIMENTION)
// 	{
// 		mlx_put_pixel(data->cub_mlx.img_map.img_ptr, x, y, 255);
// 		img[X]++;
// 		i++;
// 	}
// }

/// @brief puts the adequate pixels (depending on the flag) in the image
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place 
/// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour 
//static void	draw_map2(t_root *data, int img[2], int flag)
//{
//	uint32_t	colour[5];
//	mlx_image_t	*map;

//	map = data->cub_mlx.img_map.img_ptr;
//	colour[WALL] = ft_my_pixel(0, 6, 255, 255);
//	colour[FLOOR] = ft_my_pixel(0, 167, 255, 255);
//	colour[SPACE] = ft_my_pixel(0, 0, 0, 255);
//	if (img[X] >= 0 && img[X] < MM_DIMENTION && img[Y] >= 0 && img[Y] < MM_DIMENTION)
//	{
//		if (flag == WALL)
//			mlx_put_pixel(map, img[X], img[Y], colour[WALL]);
//		else if (flag == FLOOR)
//			mlx_put_pixel(map, img[X], img[Y], colour[FLOOR]);
//		else
//			mlx_put_pixel(map, img[X], img[Y], colour[SPACE]);
//	}
//}

///// @brief will draw only the black (space or the tiles' outlines)
///// @param data needed for map img pointer
///// @param img coordinates inside image needed to draw the pixel in the correct
//	//place
///// @param j current height in the tile in the minimap
///// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour
//static void	draw_map1(t_root *data, double mm_coord[2], int flag)
//{
//	int		i;

//	i = 0;
//	while (i < MMTW && mm_coord[X] < MM_DIMENTION)
//	{
//		draw_map2(data, mm_coord, flag);
//		mm_coord[X]++;
//		i++;
//	}
//}

///// @brief checks that the width of the minimap is correct, goes to another
//	//function checking whats on the map (1 0 N S W E ' ')
///// @param data needed for the map img pointer
///// @param y current height of the real map
///// @param img coordinates inside image needed to draw the pixel in the correct
//	//place
///// @param j current height in the tile in the minimap
//// static void	draw_map(t_root *data, int y, int mm_coord[2], double mm_start[2])
//// {
//// 	int	x;

//// 	x = 0;
//// 	while (x < MM_DIMENTION)
//// 	{
//// 		draw_rest(data, mm_coord);
//// 		x++;
//// 	}
//// }

///// @brief based on the size of minimap tiles, it checks that mini map is
//	// drawn withing the correct height of the map (taking into account the
//	// size of mini map tiles)
//void	add_mini_map(t_root *data)
//{
//	int	y;
//	int	x;
//	double	mm_coord[2];
//	double	mm_start[2];

//	mm_start[X] = data->p.x_pos - (MM_DIMENTION / MMTH / 2.0);
//	mm_start[Y] = data->p.y_pos - (MM_DIMENTION / MMTH / 2.0);
//	y = 0;
//	while (y < MM_DIMENTION)
//	{
//		x = 0;
//		while (x < MM_DIMENTION)
//		{
//			mm_coord[X] = mm_start[X] + (float)x / MMTH;
//			mm_coord[Y] = mm_start[Y] + (float)y / MMTH;
//			if (mm_coord[X] >= 0 && mm_coord[X] < data->map.lenght && mm_coord[Y] >= 0 && mm_coord[Y] < data->map.height)
//			{
//				if (data->map.map[y][x] == '1')
//					draw_map1(data, mm_coord, WALL);
//				else if (data->map.map[y][x] == '0')
//					draw_map1(data, mm_coord, FLOOR);
//				else if (data->map.map[y][x] == ' ')
//					draw_map1(data, mm_coord, SPACE);
//			}
//			else
//				mlx_put_pixel(data->cub_mlx.img_map.img_ptr, x, y, 0x0);
//			x++;
//		}
//		y++;
//	}
//	draw_player(data);
//	draw_ray(data);
//}

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
		color = ft_my_pixel(0, 0, 0, 255); // Default to SPACE color (black)

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
				mlx_put_pixel(data->cub_mlx.img_map.img_ptr, x, y, 0x000000FF); // Black for out-of-bounds
			x++;
		}
		y++;
	}

	draw_player(data);
	draw_ray(data);
}

