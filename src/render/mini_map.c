/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/20 08:34:45 by mstencel      ########   odam.nl         */
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
	while (i < MMTW)
	{
		mlx_put_pixel(data->cub_mlx.img.img_ptr, img[X], img[Y], 255);
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

	map = data->cub_mlx.img.img_ptr;
	colour[RAY] = ft_my_pixel(255, 211, 0, 198);
	colour[WALL] = ft_my_pixel(0, 6, 255, 255);
	colour[PLAYER] = ft_my_pixel(128, 0, 255, 255);
	colour[FLOOR] = ft_my_pixel(0, 167, 255, 255);
	colour[SPACE] = ft_my_pixel(0, 0, 0, 255);
	if (flag == PLAYER)
		mlx_put_pixel(map, img[X], img[Y], colour[PLAYER]);
	else if (flag == WALL)
		mlx_put_pixel(map, img[X], img[Y], colour[WALL]);
	else if (flag == FLOOR)
		mlx_put_pixel(map, img[X], img[Y], colour[FLOOR]);
	else if (flag == SPACE)
		mlx_put_pixel(map, img[X], img[Y], colour[SPACE]);
}

/// @brief will draw only the black (space or the tiles' outlines)
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place
/// @param j current height in the tile in the minimap
/// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour
static void	draw_map1(t_root *data, int mm_cord[2], int flag)
{
	int		i;

	i = 0;
	while (i < MMTW)
	{
		draw_map2(data, mm_cord, flag);
		mm_cord[X]++;
		i++;
	}
}

void draw_player(t_root *data)
{
	int width;
	int height;
	int mini_x;
	int mini_y;
	int start_x;
	int start_y;

	height = 0;
	width = 0;
	
	// Calculate the starting point for the minimap (top-left corner)
	mini_x = W - data->map->lenght * MMTW;
	mini_y = H - data->map->height * MMTH;

	// Calculate player's position relative to the minimap
	start_x = (int)(mini_x + (data->p->x_pos * MMTW) - MMPP / 2);
	start_y = (int)(mini_y + (data->p->y_pos * MMTH) - MMPP / 2);

	// Draw the player square
	while(height < MMPP)
	{
		width = 0;
		while(width < MMPP)
		{
				mlx_put_pixel(data->cub_mlx.img.img_ptr, start_x + width, start_y + height, 0xFF0000FF); // Blue color
				width++;
		}
		height++;
	}
}

/// @brief checks that the width of the minimap is correct, goes to another
	//function checking whats on the map (1 0 N S W E ' ')
/// @param data needed for the map img pointer
/// @param y current height of the real map
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place
/// @param j current height in the tile in the minimap
static void	draw_map(t_root *data, int y, int mm_cord[2])
{
	int	x;

	x = 0;
	mm_cord[X] = W - data->map->lenght * MMTW;
	while (data->map->map[y][x] && x < data->map->lenght)
	{
		draw_player(data);
		if (data->map->map[y][x] == '1')
			draw_map1(data, mm_cord, WALL);
		else if (data->map->map[y][x] == '0')
			draw_map1(data, mm_cord, FLOOR);
		else if (data->map->map[y][x] == ' ')
			draw_map1(data, mm_cord, SPACE);
		x++;
	}
	while (x < data->map->lenght)
	{
		draw_rest(data, mm_cord);
		x++;
	}
}

/// @brief based on the size of minimap tiles, it checks that mini map is
	// drawn withing the correct height of the map (taking into account the
	// size of mini map tiles)
void	add_mini_map(t_root *data)
{
	int	y;
	int	mm_cordinate[2];
	int	j;

	
	//mm_cordinate[X] = W - data->map->lenght * MMTW;
	mm_cordinate[Y] = H - data->map->height * MMTH;
	y = 0;
	while (y < data->map->height)
	{
		j = 0;
		while (j < MMTH)
		{
			draw_map(data, y, mm_cordinate);
			j++;
			mm_cordinate[Y]++;
		}
		y++;
	}
}

// void	get_mini_map(t_root *data)
// {
// 	int		x;
// 	int		y;
// 	long	width;
// 	long	height;

// 	width = data->map->lenght * MMTW;
// 	height = data->map->height * MMTH;
// 	y = H - height;
// 	while (y < H && y > 0)
// 	{
// 		x = W - width;
// 		while(x < W && x > 0)
// 		{
// 			mlx_put_pixel(data->cub_mlx.img.img_ptr, x, y, 255);
// 			x++;
// 		}
// 		y++;
// 	}
// 	add_mini_map(data);
// }
