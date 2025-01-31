/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:38:05 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/30 13:29:37 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static	int	move_player(t_root *data, double delta_x, double delta_y)
{
	double	new_x;
	double	new_y;

	new_x = data->p.x_pos + delta_x;
	new_y = data->p.y_pos + delta_y;
	
	if ((data->map.map[(int)(new_y - HITBOX)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x - HITBOX)] == '0')
	&& (data->map.map[(int)(new_y + 0.09)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x + HITBOX)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x)] == '0'))
	{
		data->p.x_pos = new_x;
		data->p.y_pos = new_y;
		printf("Player moved to: [%f][%f]\n", data->p.y_pos, data->p.x_pos);
		return (1);
	}
	else
	{
		printf("Hit the wall\n");
		return 0;
	}
}

static void turn_left(t_root *data)
{
	data->p.pos -= 1.0;
	if (data->p.pos < 0)
		data->p.pos += 360;

	data->ray.dir_x = cos(to_radiance(data->p.pos));
	data->ray.dir_y = sin(to_radiance(data->p.pos));
	handel_angel(data);
	
	}

static void turn_right(t_root *data)
{
	data->p.pos += 1.0;
	if (data->p.pos >= 360)
		data->p.pos -= 360;

	data->ray.dir_x = cos(to_radiance(data->p.pos));
	data->ray.dir_y = sin(to_radiance(data->p.pos));
	handel_angel(data);
	printf("Turned Right -> New angle: %f, dir_x: %f, dir_y: %f\n", data->p.pos, data->ray.dir_x, data->ray.dir_y);
}

static void go(t_root *data, int flag)
{
	double move_step = 0.05;

	double move_x = cos(to_radiance(data->p.pos)) * move_step;
	double move_y = sin(to_radiance(data->p.pos)) * move_step;

	if (flag == 1) // Forward
		move_player(data, move_x, move_y);
	else if (flag == 2) // Backward
		move_player(data, -move_x, -move_y);
	else if (flag == 3) // Left (Strafe)
		move_player(data, move_y, -move_x);
	else if (flag == 4) // Right (Strafe)
		move_player(data, -move_y, move_x);
}
void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_root	*data;
	
	(void)keydata;
	data = param;

	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_W))
		go(data, 1);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_S))
		go(data, 2);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_A))
		go(data, 3);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_D))
		go(data, 4);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_ESCAPE))
		mlx_close_window(data->cub_mlx.win);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_LEFT))
		turn_left(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_RIGHT))
		turn_right(data);
	add_mini_map(data);
	get_rays(data);
}
