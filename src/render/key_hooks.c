/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 10:38:05 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/18 12:42:32 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	go_forward(t_root *data)
{
	int	p_x;
	int	p_y;

	p_x = data->p->x_pos;
	p_y = data->p->y_pos;
	if (data->map->map[p_y - 1][p_x] == '0')
	{
		printf("player is now: [%d][%d]\n", p_y, p_x);
		printf("going forward\n");
		data->p->y_pos--;
		printf("player is now: [%d][%d]\n", data->p->y_pos, p_x);
	}
	else if (data->map->map[p_y - 1][p_x] == '1')
		printf("hit the wall\n");
}

static void	go_backward(t_root *data)
{
	int	p_x;
	int	p_y;

	p_x = data->p->x_pos;
	p_y = data->p->y_pos;
	if (data->map->map[p_y + 1][p_x] == '0')
	{
		printf("player is now: [%d][%d]\n", p_y, p_x);
		printf("going backward\n");
		data->p->y_pos++;
		printf("player is now: [%d][%d]\n", data->p->y_pos, p_x);
	}
	else if (data->map->map[p_y + 1][p_x] == '1')
		printf("hit the wall\n");
}

static void	turn_left(t_root *data)
{
	int	p_x;
	int	p_y;

	p_x = data->p->x_pos;
	p_y = data->p->y_pos;
	if (data->map->map[p_y][p_x - 1] == '0')
	{
		printf("player is now: [%d][%d]\n", p_y, p_x);
		printf("going backward\n");
		data->p->x_pos--;
		printf("player is now: [%d][%d]\n", data->p->y_pos, p_x);
	}
	else if (data->map->map[p_y][p_x - 1] == '1')
		printf("hit the wall\n");
}

static void	turn_right(t_root *data)
{
	int	p_x;
	int	p_y;

	p_x = data->p->x_pos;
	p_y = data->p->y_pos;
	if (data->map->map[p_y][p_x + 1] == '0')
	{
		printf("player is now: [%d][%d]\n", p_y, p_x);
		printf("going backward\n");
		data->p->x_pos++;
		printf("player is now: [%d][%d]\n", data->p->y_pos, p_x);
	}
	else if (data->map->map[p_y][p_x + 1] == '1')
		printf("hit the wall\n");
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_root	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		go_forward(data);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		go_backward(data);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		turn_left(data);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		turn_right(data);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
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
