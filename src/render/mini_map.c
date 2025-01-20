/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 14:07:46 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/20 12:10:06 by mstencel      ########   odam.nl         */
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
	else
		mlx_put_pixel(map, img[X], img[Y], colour[SPACE]);
}

/// @brief will draw only the black (space or the tiles' outlines)
/// @param data needed for map img pointer
/// @param img coordinates inside image needed to draw the pixel in the correct
	//place
/// @param j current height in the tile in the minimap
/// @param flag SPACE, FLOOR, WALL, RAY, PLAYER, for the colour


static void	draw_map1(t_root *data, int mm_coord[2], int flag)
{
	int		i;

	i = 0;
	while (i < MMTW)
	{

		draw_map2(data, mm_coord, flag);
		mm_coord[X]++;
		i++;
	}
}

// void draw_player(t_root *data)
// {
// 	int width;
// 	int height;
// 	int mini_x;
// 	int mini_y;
// 	int start_x;
// 	int start_y;

// 	height = 0;
// 	width = 0;
	
// 	// Calculate the starting point for the minimap (top-left corner)
// 	mini_x = win_w - data->map->lenght * MMTW;
// 	mini_y = win_h - data->map->height * MMTH;

// 	// Calculate player's position relative to the minimap
// 	start_x = (int)(mini_x + (data->p->x_pos * MMTW) - MMPP / 2);
// 	start_y = (int)(mini_y + (data->p->y_pos * MMTH) - MMPP / 2);

// 	// printf("mini_x = %d\tx_pos = %d\tstart_x = %d\n", mini_x, (int)data->p->x_pos * MMTW, start_x);
// 	// printf("mini_y = %d\ty_pos = %d\tstart_y = %d\n", mini_y, (int)data->p->y_pos * MMTH, start_y);
// 	// Draw the player square
// 	while(height < MMPP)
// 	{
// 		width = 0;
// 		while(width < MMPP)
// 		{
// 				mlx_put_pixel(data->cub_mlx.img.img_ptr, start_x + width, start_y + height, 0xFF0000FF); // Blue color
// 				width++;
// 		}
// 		height++;
// 	}
// }

//trying out the circle
void draw_player(t_root *data)
{
	int width; // x
	int height; // y
	int mini_x;
	int mini_y;
	int centre_player_x;
	int centre_player_y;
	int	radius;
	int	pixel_x;
	int	pixel_y;
	int	map_x;
	int	map_y;

	
	// Calculate the starting point for the minimap (top-left corner)
	mini_x = data->cub_mlx.win_w - data->map->lenght * MMTW;
	mini_y = data->cub_mlx.win_h - data->map->height * MMTH;

	// Calculate player's position relative to the minimap
	centre_player_x = (int)(mini_x + (data->p->x_pos * MMTW));
	centre_player_y = (int)(mini_y + (data->p->y_pos * MMTH));

	radius = MMPP / 2; // == 5
	height = -radius;  // -5 -> 5
	while(height <= radius)
	{
		width = -radius;
		while(width <= radius)
		{
			pixel_x = centre_player_x + width; //start of the x player
			pixel_y = centre_player_y + height; //start of the y player
			if (width * width + height * height <= radius * radius) //as long as it is withing the circle
			{
				map_x = (pixel_x - mini_x) / MMTW; //x on the real map
				map_y = (pixel_y - mini_y) / MMTH; // y on the real map
				//TODO needs to be changed to make sure it doesn't go over the corners
				if (map_x >= 0 && map_y >= 0 && map_x < data->map->lenght && map_y < data->map->height && data->map->map[map_y][map_x] != '1')
					mlx_put_pixel(data->cub_mlx.img.img_ptr, pixel_x, pixel_y, 0xFF0000FF);
			}
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
static void	draw_map(t_root *data, int y, int	mm_coord[2])
{
	int	x;

	x = 0;
	mm_coord[X] = data->cub_mlx.win_w - data->map->lenght * MMTW;
	while (data->map->map[y][x])
	{
		draw_player(data);
		if (data->map->map[y][x] == '1')
			draw_map1(data, mm_coord, WALL);
		else if (data->map->map[y][x] == '0')
			draw_map1(data, mm_coord, FLOOR);
		else if (data->map->map[y][x] == ' ')
			draw_map1(data, mm_coord, SPACE);
		x++;
	}
	while (x < data->map->lenght)
	{
		draw_rest(data, mm_coord);
		x++;
	}
}

/// @brief based on the size of minimap tiles, it checks that mini map is
	// drawn withing the correct height of the map (taking into account the
	// size of mini map tiles)
void	add_mini_map(t_root *data)
{
	int	y;
	int	mm_coord[2];
	int	tile_y;

	//[X] = W - data->map->lenght * MMTW;
	mm_coord[Y] = data->cub_mlx.win_h - data->map->height * MMTH;
	y = 0;
	while (y < data->map->height)
	{
		tile_y = 0;
		while (tile_y < MMTH)
		{
			draw_map(data, y, mm_coord);
			mm_coord[Y]++;
			tile_y++;
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
