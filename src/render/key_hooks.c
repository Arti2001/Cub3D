/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 10:38:05 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/23 13:12:54 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

# define HITBOX 0.05

static	int	move_player(t_root *data, double delta_x, double delta_y)
{
	double	new_x;
	double	new_y;

	new_x = data->p->x_pos + delta_x;
	new_y = data->p->y_pos + delta_y;
	
	if ((data->map->map[(int)(new_y - HITBOX)][(int)(new_x)] == '0')
	&& (data->map->map[(int)(new_y)][(int)(new_x - HITBOX)] == '0')
	&& (data->map->map[(int)(new_y + 0.09)][(int)(new_x)] == '0')
	&& (data->map->map[(int)(new_y)][(int)(new_x + HITBOX)] == '0')
	&& (data->map->map[(int)(new_y)][(int)(new_x)] == '0'))
	{
		data->p->x_pos = new_x;
		data->p->y_pos = new_y;
		printf("Player moved to: [%f][%f]\n", data->p->y_pos, data->p->x_pos);
		return (1);
	}
	else
	{
		printf("Hit the wall\n");
		return 0;
	}
}


static void go_forward(t_root *data)
{
	printf("Going forward\n");
	move_player(data, 0.0, -0.05);
}
static void go_backward(t_root *data)
{
	printf("Going backward\n");
	move_player(data, 0.0, 0.05);
}
static void go_left(t_root *data)
{
	printf("Going left\n");
	move_player(data, -0.05, 0.0);
}
static void go_right(t_root *data)
{
	printf("Going right\n");
	move_player(data, 0.05, 0.0);
}

static	void	turn_left(t_root *data)
{
	data->p->most_l -= 1.0;
	data->p->most_r -= 1.0;
	if (data->p->most_l < 1.0)
		data->p->most_l = 360.0;
	if (data->p->most_r < 1.0)
		data->p->most_r = 360.0;
	printf("left -> %f <====> right-> %f\n", data->p->most_l, data->p->most_r);
}

static	void	turn_right(t_root *data)
{
	data->p->most_r += 1.0;
	data->p->most_l += 1.0;
	if (data->p->most_r > 360.0)
		data->p->most_r = 1.0;
	if (data->p->most_l > 360.0)
		data->p->most_l = 1.0;
	printf("left -> %f <====> right-> %f\n", data->p->most_l, data->p->most_r);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_root	*data;
	
	(void)keydata;
	data = param;
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_W))
		go_forward(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_S))
		go_backward(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_A))
		go_left(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_D))
		go_right(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_LEFT))
		turn_left(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_RIGHT))
		turn_right(data);
	if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_ESCAPE))
		mlx_close_window(data->cub_mlx.win);;
	add_mini_map(data);
	// if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_W))
	// 	go_forward(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_S))
	// 	go_backward(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_A))
	// 	turn_left(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_D))
	// 	turn_right(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_ESCAPE))
	// 	close_game(data);
}
