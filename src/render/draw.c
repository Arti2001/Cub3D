/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 10:14:41 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/06 15:00:16 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	wall_info(t_root *data, t_wall *wall)
{
	if (data->ray.side == EAST || data->ray.side == WEST)
		wall->hit_point = data->p.y_pos + (data->ray.distance * data->ray.dir_y);
	else
		wall->hit_point = data->p.x_pos + data->ray.distance * data->ray.dir_x;
	wall->hit_point -= floor(wall->hit_point);

	
	wall->height = (int)(data->cub_mlx.win_h / data->ray.distance);
	wall->start = (int)((data->cub_mlx.win_h - wall->height) / 2);
	if (wall->start < 0)
		wall->start = 0;
	wall->end = (int)(wall->height + data->cub_mlx.win_h) / 2;
	if (wall->end > data->cub_mlx.win_h)
		wall->end = data->cub_mlx.win_h - 1;
	wall->map_tile = data->map.map[data->ray.x_map][data->ray.y_map] - 1;
	wall->tex_width = data->textures[wall->side]->width;
	wall->tex_height = data->textures[wall->side]->height;
	wall->tex_x = (int)(wall->hit_point * (double)wall->tex_width);
	if ((wall->side == EAST || wall->side == WEST) && data->ray.dir_x > 0)
		wall->tex_x = wall->tex_width - wall->tex_x - 1;
	if ((wall->side == NORTH || wall->side == SOUTH) && data->ray.dir_y < 0)
		wall->tex_x = wall->tex_width - wall->tex_x - 1;
	wall->step = 1.0 * wall->tex_height / wall->height;
	wall->tex_pos = (wall->start - data->cub_mlx.win_h / 2 + wall->height / 2) * wall->step;
}

void	draw_wall(t_root *data, int i, int j, t_wall *wall)
{
	mlx_texture_t	*texture;
	int	pix;
	int	rgba[4];

	texture = data->textures[wall->side];
	wall->tex_y = (int)wall->tex_pos;
	if (wall->tex_y >= (int)wall->tex_height)
		wall->tex_y = wall->tex_height - 1;
	wall->tex_pos += wall->step;
	
	pix = (wall->tex_x + wall->tex_y * wall->tex_width) * 4;
	rgba[0] = texture->pixels[pix];
	rgba[1] = texture->pixels[pix + 1];
	rgba[2] = texture->pixels[pix + 2];
	rgba[3] = texture->pixels[pix + 3];
	mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ft_my_pixel(rgba[0], rgba[1], rgba[2], rgba[3]));
}

static bool	mm_check(t_root *data, int i, int j)
{
	if ((i <= data->map.mm_start_x && j <= data->map.mm_start_y) \
		|| ((i > data->map.mm_start_x && j < data->map.mm_start_y) \
		|| (j > data->map.mm_start_y && i < data->map.mm_start_x)))
		return (true);
	return (false);
}

static void	draw_screen(t_root *data, int i, uint32_t ceil, uint32_t fl)
{
	t_wall		wall;
	int			j;

	j = 0;
	ft_bzero(&wall, sizeof(t_wall));
	wall_info(data, &wall);
	while (j < data->cub_mlx.win_h)
	{
		if (j < wall.start && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ceil);
		else if (j >= wall.start && j <= wall.end && mm_check(data, i, j) == true)
		{
			if (data->ray.side == EAST)
				mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ft_my_pixel(56, 74, 0, 255));
			else if (data->ray.side == WEST)
				mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ft_my_pixel(125, 12, 0, 255));
			else if (data->ray.side == NORTH)
				mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ft_my_pixel(0, 0, 0, 255));
			else if (data->ray.side == SOUTH)
				mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, ft_my_pixel(255, 255, 255, 255));
		}
			// draw_wall(data, i, j, &wall);
		else if (j > wall.end && mm_check(data, i, j) == true)
			mlx_put_pixel(data->cub_mlx.img.img_ptr, i, j, fl);
		j++;
	}
}

// get_rays(data, i) is doing doing all the math 
// (getting the distance between the wall & the player)
void	draw_game(void *param)
{
	t_root		*data;
	int			i;
	uint32_t	ceil;
	uint32_t	fl;

	data = param;
	i = 0;
	ceil = ft_my_pixel(data->map.ceiling.r, data->map.ceiling.g, \
		data->map.ceiling.b, 255);
	fl = ft_my_pixel(data->map.floor.r, data->map.floor.g, \
		data->map.floor.b, 255);
	while (i < data->cub_mlx.win_w)
	{
		get_rays(data, i);
		draw_screen(data, i, ceil, fl);
		i++;
	}
	add_mini_map(data);
}
