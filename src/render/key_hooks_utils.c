/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 08:36:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/10 09:40:48 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	can_move(t_root *data, double new_x, double new_y)
{
	if ((data->map.map[(int)(new_y - HITBOX)][(int)(new_x)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x - HITBOX)] == '0')
		&& (data->map.map[(int)(new_y + HITBOX)][(int)(new_x)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x + HITBOX)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x)] == '0'))
		return (true);
	return (false);
}

// static void	go_up_down(t_root *data, double move_step, double new_x, double new_y)
// {
// 	printf("I'm in go_up_down\n");
// 	new_y = data->p.y_pos - move_step;
// 	if (can_move(data, new_x, new_y) == true)
// 	{
// 		data->p.y_pos = new_y;
// 		return ;
// 	}
// 	new_y = data->p.y_pos + move_step;
// 	if (can_move(data, new_x, new_y) == true)
// 	{
// 		data->p.y_pos = new_y;
// 		return ;
// 	}
// }

// static void	go_right_left(t_root *data, double move_step, double new_x, double new_y)
// {
// 	printf("I'm in go_right_left\n");
// 	new_x = data->p.x_pos + move_step;
// 	if (can_move(data, new_x, new_y) == true)
// 	{
// 		data->p.x_pos = new_x;
// 		return ;
// 	}
// 	new_x = data->p.x_pos - move_step;
// 	if (can_move(data, new_x, new_y) == true)
// 	{
// 		data->p.x_pos = new_x;
// 		return ;
// 	}
// }

// void	along_the_wall(t_root *data, double move_step, int flag)
// {
// 	double	player_wall_angle;
// 	double	new_x;
// 	double	new_y;

// 	printf("I'm in the along the wall\n");
// 	player_wall_angle = atan2(data->p.y_dir, data->p.x_dir);
// 	new_x = data->p.x_pos + data->p.x_dir * move_step;
// 	new_y = data->p.y_pos + data->p.y_dir * move_step;
// 	if (flag == FORWARD_BACKWARD)
// 	{
// 		if ((flag == FORWARD_BACKWARD && (fabs(data->p.x_dir) > fabs(data->p.y_dir)))
// 		|| (flag == LEFT_RIGHT && (fabs(data->p.plane_x) > fabs(data->p.plane_y))))
// 		{
// 			go_up_down(data, move_step, new_x, new_y);
// 			return ;
// 		}
// 		else
// 		{
// 			go_right_left(data, move_step, new_x, new_y);
// 			return ;
// 		}
// 	}
// }
