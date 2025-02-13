/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 10:38:05 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/13 10:27:22 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	move_player_sides(t_root *data, double move_step)
{
	double	new_x;
	double	new_y;

	new_x = data->p.x_pos + data->p.plane_x * move_step;
	new_y = data->p.y_pos + data->p.plane_y * move_step;
	if ((data->map.map[(int)(new_y - HB)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x - HB)] == '0')
	&& (data->map.map[(int)(new_y + HB)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x + HB)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x)] == '0'))
	{
		data->p.x_pos = new_x;
		data->p.y_pos = new_y;
		return (1);
	}
	else
		return (0);
}

static	int	move_player(t_root *data, double move_step)
{
	double	new_x;
	double	new_y;

	new_x = data->p.x_pos + data->p.x_dir * move_step;
	new_y = data->p.y_pos + data->p.y_dir * move_step;
	if ((data->map.map[(int)(new_y - HB)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x - HB)] == '0')
	&& (data->map.map[(int)(new_y + HB)][(int)(new_x)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x + HB)] == '0')
	&& (data->map.map[(int)(new_y)][(int)(new_x)] == '0'))
	{
		data->p.x_pos = new_x;
		data->p.y_pos = new_y;
		return (1);
	}
	else
		return (0);
}

static void	turn_player(t_root *data, double move_step)
{
	double	new_plane_x;
	double	new_x_direction;

	new_plane_x = data->p.plane_x * cos(move_step) - data->p.plane_y \
		* sin(move_step);
	data->p.plane_y = data->p.plane_x * sin(move_step) + data->p.plane_y \
		* cos(move_step);
	new_x_direction = data->p.x_dir * cos(move_step) - data->p.y_dir \
		* sin(move_step);
	data->p.y_dir = data->p.x_dir * sin(move_step) + data->p.y_dir \
		* cos(move_step);
	data->p.plane_x = new_plane_x;
	data->p.x_dir = new_x_direction;
}

static void	go(t_root *data, int flag)
{
	double	move_step;

	move_step = 0.05;
	if (flag == FORWARD)
		move_player(data, move_step);
	else if (flag == BACKWARD)
		move_player(data, -move_step);
	else if (flag == LEFT_MOVE)
		move_player_sides(data, -move_step);
	else if (flag == RIGHT_MOVE)
		move_player_sides(data, move_step);
	else if (flag == TURN_RIGHT)
		turn_player(data, -move_step);
	else if (flag == TURN_LEFT)
		turn_player(data, move_step);
}

void	key_hooks( void *param)
{
	t_root	*data;

	data = param;
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_W))
		go(data, FORWARD);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_S))
		go(data, BACKWARD);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_D))
		go(data, RIGHT_MOVE);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_A))
		go(data, LEFT_MOVE);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_LEFT))
		go(data, TURN_RIGHT);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_RIGHT))
		go(data, TURN_LEFT);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->cub_mlx.win);
		free_mlx(data);
		free_data(data);
		exit(EXIT_SUCCESS);
	}
}
